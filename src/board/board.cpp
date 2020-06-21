#include <iostream>

#include "board.h"


Board::Board()
    : active_block_(new Block(Block::getRandomShape())),
      holded_block_(new Block(Block::J)),
      waiting_blocks_(),
      fragments_()
{
  for (int i = 0; i < wb_count_; i++)
    waiting_blocks_.push_back(new Block(Block::getRandomShape(i)));
}

Board::~Board()
{
  delete active_block_;
  delete holded_block_;
}


void Board::holdAB()
{
  active_block_->swapBlock(holded_block_);
  std::cout << "Hold block" << std::endl;
  
  active_block_->printInfo();
}

void Board::moveAB(Shifting::Value direction) const
{
  std::cout << "Move block: " << std::endl;
  if (direction == Shifting::LEFT)
  {
    if (!isABOnLeftWall()) active_block_->moveBlock(Shifting::LEFT);
  }
  if (direction == Shifting::RIGHT)
  {
    if (!isABOnRightWall()) active_block_->moveBlock(Shifting::RIGHT);
  }
  if (direction == Shifting::DOWN)
  {
    if (!isABOnBottomWall()) active_block_->moveBlock(Shifting::DOWN);
  }
  active_block_->printInfo();
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
  active_block_->printInfo();
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

const Block::ShapeType Board::getWBShapeType(int index) const
{
  return waiting_blocks_.at(index)->getShapeType();
}


void Board::loopABCell(std::function<void(int, int)> function)
{
  loopBlockCell(*active_block_, [&function](int i, int j){
    function(j, i);
  });
}

void Board::loopHBCell(std::function<void(int, int)> function)
{
  loopBlockCell(*holded_block_, [&function](int i, int j){
    function(j, i);
  });
}

void Board::loopWBCell(int index, std::function<void(int, int)> function)
{
  loopBlockCell(*(waiting_blocks_.at(index)), [&function](int i, int j){
    function(j, i);
  });
}


// private //
const bool Board::isABOnLeftWall() const
{
  bool is_ab_on_left_wall = false;
  loopBlockCell(*active_block_, [this, &is_ab_on_left_wall](int i, int j){
    if (active_block_->getPosition().x_ + j <= 0)
      is_ab_on_left_wall = true;
  });
  return is_ab_on_left_wall;
}

const bool Board::isABOnRightWall() const
{
  bool is_ab_on_right_wall = false;
  loopBlockCell(*active_block_, [this, &is_ab_on_right_wall](int i, int j){
    if (active_block_->getPosition().x_ + j >= ab_zone_width_ - 1)
      is_ab_on_right_wall = true;
  });
  return is_ab_on_right_wall;
}

const bool Board::isABOnBottomWall() const
{
  bool is_ab_on_bottom_wall = false;
  loopBlockCell(*active_block_, [this, &is_ab_on_bottom_wall](int i, int j){
    if (active_block_->getPosition().y_ + i >= ab_zone_height_ - 1)
      is_ab_on_bottom_wall = true;
  });
  return is_ab_on_bottom_wall;
}


const bool Board::isABOnFragments() const
{
  const auto& shape = active_block_->getShape();

  return false;
}


void Board::loopBlockCell(Block& block, std::function<void(int, int)> function) const
{
  const auto& shape = block.getShape();
  for (unsigned int i = 0; i < shape.size(); i++)
    for (unsigned int j = 0; j < shape.at(i).size(); j++)
      if (shape.at(i).at(j))
        function(i, j);
}
