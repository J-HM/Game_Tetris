#include <iostream>

#include "board.h"


const int Board::board_width_ = 10;
const int Board::board_height_ = 20;

Board::Board()
    : active_block_(new Block(Block::getRandomShape())),
      holded_block_(new Block(Block::EMPTY)),
      waiting_blocks_(),
      fragments_()
{
  waiting_blocks_.push(Block(Block::getRandomShape(12)));
  waiting_blocks_.push(Block(Block::getRandomShape(23)));
  waiting_blocks_.push(Block(Block::getRandomShape(34)));
}

Board::~Board()
{
  delete active_block_;
  delete holded_block_;
}

const Board::Wall Board::getWallABlockOn() const
{
  const auto& shape = active_block_->getShape();
  for (unsigned int i = 0; i < shape.size(); i++)
  {
    for (unsigned int j = 0; j < shape.at(i).size(); j++)
    {
      if (shape.at(i).at(j))
      {
        if (active_block_->getPositionY() + i == board_height_ - 1)
          return BOTTOM;
        if (active_block_->getPositionX() + j == board_width_ - 1)
          return RIGHT;
        if (active_block_->getPositionX() + j == 0)
          return LEFT;

      }
    }
  }
  return BETWEEN;
}

const bool Board::checkABlockOnFragments() const
{
  const auto& shape = active_block_->getShape();
  for (unsigned int i = 0; i < shape.size(); i++)
  {
    for (unsigned int j = 0; j < shape.at(i).size(); j++)
    {
      if (shape.at(i).at(j))
      {
        if (active_block_->getPositionX() + j == board_width_ - 1)
          return true;
        if (active_block_->getPositionX() + j == 0)
          return true;
      }
    }
  }
  return false;
}

void Board::holdABlock()
{
  active_block_->swapBlock(holded_block_);
  std::cout << "Hold block" << std::endl;
  active_block_->printInfo();
}

void Board::moveABlockRight()
{
  if (getWallABlockOn() != Board::Wall::RIGHT)
  {
    active_block_->moveBlock(Shifting::RIGHT);
    std::cout << "Move block Right" << std::endl;
    active_block_->printInfo();
  }
}

void Board::moveABlockLeft()
{
  if (getWallABlockOn() != Board::Wall::LEFT)
  {
    active_block_->moveBlock(Shifting::LEFT);
    std::cout << "Move block Left: " << std::endl;
    active_block_->printInfo();
  }
}

void Board::rotateABlockCw()
{
  active_block_->rotateBlock(Rotation::CW);
  std::cout << "Rotate block Left: " << std::endl;
  active_block_->printInfo();
}

void Board::rotateABlockAcw()
{
  // Check block is overlap with other Block
  active_block_->rotateBlock(Rotation::ACW);
  std::cout << "Rotate block Left" << std::endl;
  active_block_->printInfo();
}

const bool Board::dropABlockNormal()
{
  if (getWallABlockOn() != Board::Wall::BOTTOM)
  {
    active_block_->moveBlock(Shifting::DOWN);
    return true;
  }
  else
  {
    return false;
  }
}

const bool Board::dropABlockSoft()
{
  active_block_->moveBlock(Shifting::DOWN);
  return true;
  //TODO implement dropHard
}

const bool Board::dropABlockHard()
{
  return true;
  //TODO implement dropHard
}

const int Board::getABlockPositionX() const
{
  return active_block_->getPositionX();
}

const int Board::getABlockPositionY() const
{
  return active_block_->getPositionY();
}

const Block::ShapeType Board::getABlockShapeType() const
{
  return active_block_->getShapeType();
}


void Board::doForEachABlockCell(std::function<void(int, int)> drawCell)
{
  const auto& shape = active_block_->getShape();
  for (unsigned int i = 0; i < shape.size(); i++)
  {
    for (unsigned int j = 0; j < shape.at(i).size(); j++)
    {
      if (shape.at(i).at(j))
        drawCell(j, i); // (x, y)
    }
  }
}
