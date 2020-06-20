#include <iostream>
#include "board.h"


Board::Board()
    : active_block_(new Block(Block::getRandomShape())),
      holded_block_(new Block(Block::J)),
      waiting_blocks_(),
      fragments_()
{
  for (int i = 0; i < wb_count_; i++)
    waiting_blocks_.push_back(new Block(Block::getRandomShape()));
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

const bool Board::moveAB(Shifting::Value direction) const
{
  std::cout << "Move block: " << std::endl;
  if (direction == Shifting::LEFT)
  {
    if (getWallABlockOn() != Wall::LEFT)
      active_block_->moveBlock(Shifting::LEFT);
    else
      return false;
  }
  else if (direction == Shifting::RIGHT)
  {
    if (getWallABlockOn() != Wall::RIGHT)
      active_block_->moveBlock(Shifting::RIGHT);
    else
      return false;
  }
  else
  {
    return false;
  }
  active_block_->printInfo();
  return true;
}

const bool Board::rotateAB(Rotation::Value direction) const
{
  // TODO wall kick
  std::cout << "Rotate block Left: " << std::endl;
  if (direction == Rotation::CW)
  {
    active_block_->rotateBlock(Rotation::CW);
    return true;
  }
  else if (direction == Rotation::ACW)
  {
    active_block_->rotateBlock(Rotation::ACW);
    return true;
  }
  else
  {
    return false;
  }
  active_block_->printInfo();
}

const bool Board::dropAB()
{
  if (getWallABlockOn() != Wall::BOTTOM)
  {
    active_block_->moveBlock(Shifting::DOWN);
    return true;
  }
  else
  {
    return false;
  }
}

const bool Board::dropABHard()
{
  return true;
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

void Board::loopWBCell(std::function<void(int, int)> function)
{
  loopBlockCell(*(waiting_blocks_.at(1)), [&function](int i, int j){
    function(j, i);
  });
}


// private //
const Board::Wall Board::getWallABlockOn() const
{
  auto wall_ablock_on = BETWEEN;
  loopBlockCell(*active_block_, [this, &wall_ablock_on](int i, int j){
    if (active_block_->getPosition().y_ + i == ab_zone_height_ - 1)
      wall_ablock_on = BOTTOM;
    if (active_block_->getPosition().x_ + j == ab_zone_width_ - 1)
      wall_ablock_on = RIGHT;
    if (active_block_->getPosition().x_ + j == 0)
      wall_ablock_on = LEFT;
  });
  return wall_ablock_on;
}


const bool Board::checkABlockOnFragments() const
{
  const auto& shape = active_block_->getShape();

  return false;
}


void Board::loopBlockCell(Block& block, std::function<void(short int, short int)> function) const
{
  const auto& shape = active_block_->getShape();
  for (unsigned int i = 0; i < shape.size(); i++)
  {
    for (unsigned int j = 0; j < shape.at(i).size(); j++)
    {
      if (shape.at(i).at(j))
      {
        function(i, j);
      }
    }
  }
}
