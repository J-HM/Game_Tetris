#include <iostream>

#include "board.h"


const int Board::board_width = 10;
const int Board::board_height = 20;

Board::Board()
    : grids_({}), // initialize gird to zero
      active_block_(new Block(Block::l_shape_list_)),
      holded_block_(new Block(Block::l_shape_list_))
{
  active_block_->printInfo();
}

Board::~Board()
{
  delete active_block_;
  delete holded_block_;
}

void Board::holdBlock()
{
  active_block_->swapBlock(holded_block_);
  std::cout << "Hold block" << std::endl;
  active_block_->printInfo();
}

void Board::moveBlockRight()
{
  // Check position is < 20
  active_block_->moveBlock(Shifting::RIGHT);
  std::cout << "Move block Right" << std::endl;
  active_block_->printInfo();
}

void Board::moveBlockLeft()
{
  // Check position is > 0
  active_block_->moveBlock(Shifting::LEFT);
  std::cout << "Move block Left: " << std::endl;
  active_block_->printInfo();
}

void Board::rotateBlockCW()
{
  // Check block is overlap with other Block
  active_block_->rotateBlock(Rotation::CW);
  std::cout << "Rotate block Left: " << std::endl;
  active_block_->printInfo();
}

void Board::rotateBlockACW()
{
  // Check block is overlap with other Block
  active_block_->rotateBlock(Rotation::ACW);
  std::cout << "Rotate block Left" << std::endl;
  active_block_->printInfo();
}

void Board::dropBlockHard()
{
  //TODO implement dropHard
}

void Board::dropBlockSoft()
{
  //TODO implement dropHard
}

