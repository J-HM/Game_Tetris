#include <iostream>

#include "board.hpp"


Board::Board()
    : active_block_(new Block(Block::getRandomShape())),
      holded_block_(new Block(Block::EMPTY)),
      waiting_blocks_(),
      fragments_(),
      is_ab_falling_(true),
      is_swapped_(false)
{
  for (int i = 0; i < wb_count_; i++)
    waiting_blocks_.push_back(new Block(Block::getRandomShape()));
}

Board::~Board()
{
  delete active_block_;
  delete holded_block_;
}


void Board::swapABwithHB()
{
  if (is_swapped_) return void();
  std::cout << "Swap block:" << std::endl;
  active_block_->setPosition(Position(3, 0));
  std::swap(active_block_, holded_block_);
  if (active_block_->getShapeType() == Block::EMPTY)
  {
    delete active_block_;
    active_block_ = *(waiting_blocks_.begin());
    waiting_blocks_.pop_front();
    waiting_blocks_.push_back(new Block(Block::getRandomShape()));
  }
  is_swapped_ = true;
  active_block_->printStatus();
}

void Board::moveAB(Shifting::Value direction)
{
  std::cout << "Move block: " << std::endl;
  if (direction == Shifting::LEFT)
  {
    if (!isABOnLeftWall()) active_block_->moveBlock(Shifting::LEFT);
  }
  else if (direction == Shifting::RIGHT)
  {
    if (!isABOnRightWall()) active_block_->moveBlock(Shifting::RIGHT);
  }
  else if (direction == Shifting::DOWN)
  {
    if (!isABOnBottomWall()) active_block_->moveBlock(Shifting::DOWN);
    else is_ab_falling_ = false;
  }
  else
  {
    std::cout << "Warning: Wrong direction." << std::endl;
  }
  active_block_->printStatus();
}

void Board::rotateAB(Rotation::Value direction) const
{
  // TODO wall kick
  std::cout << "Rotate block Left: " << std::endl;
  if (direction == Rotation::CW)
  {
    active_block_->rotateBlock(Rotation::CW);
  }
  if (direction == Rotation::ACW)
  {
    active_block_->rotateBlock(Rotation::ACW);
  }
  active_block_->printStatus();
}

void Board::dropABHard()
{
  //TODO implement dropHard
}


const Position& Board::getABPosition() const
{
  return active_block_->getPosition();
}


const Block::ShapeType Board::getABShapeType() const
{
  return active_block_->getShapeType();
}

const Block::ShapeType Board::getHBShapeType() const
{
  return holded_block_->getShapeType();
}

const Block::ShapeType Board::getWBhapeType(int index) const
{
  return waiting_blocks_.at(index)->getShapeType();
}


void Board::loopABCells(std::function<bool(int, int)> function) const
{
  loopBlockCell(*active_block_, [&function](int x, int y)
  {
    return function(x, y); // Returning false makes loop keep working
  });
}

void Board::loopHBCells(std::function<bool(int, int)> function) const
{
  loopBlockCell(*holded_block_, [&function](int x, int y)
  {
    return function(x, y); // Returning false makes loop keep working
  });
}

void Board::loopWBCells(int index, std::function<bool(int, int)> function) const
{
  loopBlockCell(*(waiting_blocks_.at(index)), [&function](int x, int y)
  {
    return function(x, y);  // Returning false makes loop keep working
  });
}

void Board::loopFragments(std::function<bool(Block::ShapeType, int, int)> function) const
{ 
  for (auto fragment : fragments_.getVector())
  {
    const auto& position = fragment->getPosition();
    function(fragment->getShapeType(), position.x_, position.y_);
  }
}


void Board::popWBToAB()
{
  is_ab_falling_ = true;
  delete active_block_;
  active_block_ = *(waiting_blocks_.begin());
  waiting_blocks_.pop_front();
  waiting_blocks_.push_back(new Block(Block::getRandomShape()));
  is_swapped_ = false;
}


const bool Board::getIsABFalling() const
{
  return is_ab_falling_;
}

const bool Board::getIsSwapped() const
{
  return is_swapped_;
}


void Board::putABtoFrags()
{
  const auto& shape_type = active_block_->getShapeType();
  const auto& position = active_block_->getPosition();
  loopBlockCell(*active_block_, [&fragments = fragments_, &shape_type, &position](int x, int y) 
  {
    int position_x = position.x_ + x;
    int position_y = position.y_ + y;
    fragments.push_back(new Fragment(Position(position_x, position_y), shape_type));
    return false; // Returning false makes loop keep working
  });
}

const bool Board::checkFragsLine() const
{
  // TODO
  return false;
}

void Board::deleteFragsLine(int y)
{
  // TODO
}


const bool Board::isABOnLeftWall() const
{
  if (active_block_->getPosition().x_ > 0) 
    return false;
  return loopBlockCell(*active_block_, [&active_block_ = active_block_](int x, int y)
  {
    if (active_block_->getPosition().x_ + x <= 0)
      return true;
    else 
      return false;
  });
}

const bool Board::isABOnRightWall() const
{
  if (active_block_->getPosition().x_ + active_block_->getContainerWidth() < ab_zone_width_) 
    return false;
  return loopBlockCell(*active_block_, [&active_block_ = active_block_](int x, int y)
  {
    if (active_block_->getPosition().x_ + x >= ab_zone_width_ - 1)
      return true;
    else
      return false;
  });
}

const bool Board::isABOnBottomWall() const
{
  if (active_block_->getPosition().y_ + active_block_->getContainerHeight() < ab_zone_height_) 
    return false;
  return loopBlockCell(*active_block_, [&active_block_ = active_block_](int x, int y)
  {
    if (active_block_->getPosition().y_ + y >= ab_zone_height_ - 1)
      return true;
    else
      return false;
  });
}


const bool Board::isABOnFrags() const
{
  return loopBlockCell(*active_block_, [&active_block_ = active_block_](int x, int y)
  {
    // Position active_block_positiom(active_block_->getPosition().x_, active_block_->getPosition().y_);
    if (active_block_->getPosition().y_ + y >= ab_zone_height_ - 1)
      return true;
    else
      return false;
  });
}


const bool Board::loopBlockCell(Block& block, std::function<bool(int, int)> function) const
{
  // If function returns true, loop breaks.
  bool result = false;
  const auto& shape = block.getShape();
  for (size_t y = 0; y < shape.size(); y++)
  {
    for (size_t x = 0; x < shape.at(y).size(); x++)
    {
      if (shape.at(y).at(x)) result = function(x, y);
      if (result) break;
    }
    if (result) break;
  }
  return result;
}