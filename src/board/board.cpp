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


void Board::loopABCells(const std::function<bool(int, int)>& function) const
{
  active_block_->loopCell([&function](int x, int y)
  {
    return function(x, y); // Returning false from function makes loop keep working
  });
}

void Board::loopHBCells(const std::function<bool(int, int)>& function) const
{
  holded_block_->loopCell([&function](int x, int y)
  {
    return function(x, y); // Returning false makes loop keep working
  });
}

void Board::loopWBCells(int index, const std::function<bool(int, int)>& function) const
{
  waiting_blocks_.at(index)->loopCell([&function](int x, int y)
  {
    return function(x, y);  // Returning false makes loop keep working
  });
}

void Board::loopFrags(std::function<bool(Fragment&, Block::ShapeType)>&& function) const
{
  fragments_.loopFrags(function);
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


void Board::pushABtoFrags()
{
  fragments_.pushBlock(*active_block_);
}

void Board::checkFrags()
{
  int highest_frag_position_y = fragments_.getHighestFrag().getPosition().y_;
  for (int i = highest_frag_position_y; i < ab_zone_height_; i++)
  {
    if (fragments_.isFullRow(i))
    {
      fragments_.clearRow(i);
      for (int j = i - 1; j >= highest_frag_position_y; j--)
        fragments_.moveDownRow(j);
    }
  }
}


const bool Board::isABOnLeftWall() const
{
  if (active_block_->getPosition().x_ > 0) 
    return false;
  return active_block_->loopCell([&active_block_ = active_block_](int x, int y)
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
  return active_block_->loopCell([&active_block_ = active_block_](int x, int y)
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
  return active_block_->loopCell([&active_block_ = active_block_](int x, int y)
  {
    if (active_block_->getPosition().y_ + y >= ab_zone_height_ - 1)
      return true;
    else
      return false;
  });
}


const bool Board::isABOnFrags() const
{
  return active_block_->loopCell([&active_block_ = active_block_](int x, int y)
  {
    if (active_block_->getPosition().y_ + y >= ab_zone_height_ - 1)
      return true;
    else
      return false;
  });
}