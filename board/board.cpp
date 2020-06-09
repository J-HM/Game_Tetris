#include <iostream>

#include "board.h"


const int Board::board_width_ = 10;
const int Board::board_height_ = 20;

Board::Board()
    : active_block_(new Block(Block::getRandomShape())),
      holded_block_(new Block(Block::EMPTY)),
      fragments_()
{
  active_block_->printInfo();
}

Board::~Board()
{
  delete active_block_;
  delete holded_block_;
}

const bool Board::isActiveBlockOut() const
{
  const auto& shape = active_block_->getShape();
  for (unsigned int i = 0; i < shape.size(); i++)
  {
    for (unsigned int j = 0; j < shape.at(i).size(); j++)
    {
      if (shape.at(i).at(j))
      {
        if (active_block_->getPositionX() + j > board_width_ - 1)
          return true;
        if (active_block_->getPositionX() + j < 0)
          return true;
      }
    }
  }
  return false;
}

void Board::holdActiveBlock()
{
  active_block_->swapBlock(holded_block_);
  std::cout << "Hold block" << std::endl;
  active_block_->printInfo();
}

void Board::moveActiveBlockRight()
{
  active_block_->moveBlock(Shifting::RIGHT);
  std::cout << "Move block Right" << std::endl;
  if (isActiveBlockOut())
    active_block_->moveBlock(Shifting::LEFT);
  active_block_->printInfo();
}

void Board::moveActiveBlockLeft()
{
  active_block_->moveBlock(Shifting::LEFT);
  std::cout << "Move block Left: " << std::endl;
  if (isActiveBlockOut())
    active_block_->moveBlock(Shifting::RIGHT);
  active_block_->printInfo();
}

void Board::rotateActiveBlockCw()
{
  active_block_->rotateBlock(Rotation::CW);
  std::cout << "Rotate block Left: " << std::endl;
  active_block_->printInfo();
}

void Board::rotateActiveBlockAcw()
{
  // Check block is overlap with other Block
  active_block_->rotateBlock(Rotation::ACW);
  std::cout << "Rotate block Left" << std::endl;
  active_block_->printInfo();
}

void Board::dropActiveBlockHard()
{
  //TODO implement dropHard
}

void Board::dropActiveBlockSoft()
{
  //TODO implement dropHard
}

const int Board::getActiveBlockPositionX() const
{
  return active_block_->getPositionX();
}

const int Board::getActiveBlockPositionY() const
{
  return active_block_->getPositionY();
}

const Block::ShapeType Board::getActivBlockShapeType() const
{
  return active_block_->getShapeType();
}

void Board::doForEachBlockCell(std::function<void(int, int)> drawCell)
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
