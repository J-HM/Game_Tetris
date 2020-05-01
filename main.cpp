#include <iostream>

#include "block/block.h"

using namespace std;

int main()
{
  Block* i_block = new IBlock();

  i_block->printBlock();
  cout << endl;

  i_block->rotateBlock(Rotation::CW);
  i_block->printBlock();
  cout << endl;

  i_block->rotateBlock(Rotation::ACW);
  i_block->printBlock();
  cout << endl;

//  i_block->rotateBlock(Direction::Rotation::CW);
//  i_block->printBlock();
//  cout << endl;
//
//  i_block->rotateBlock(Direction::Rotation::CW);
//  i_block->printBlock();
  cout << endl;

  return 0;
}

