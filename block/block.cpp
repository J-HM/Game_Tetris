#include "block.h"
#include <iostream>

using std::vector;

Block::Block(const vector<vector<vector<bool>>>& k_block_shape_list)
    : k_block_shape_(&k_block_shape_list.at(0)),
      shape_type_(0),
      k_block_shape_list_(k_block_shape_list),
      is_focusing_(false)
{ }

void Block::rotateBlock(Rotation rotation)
{
  if (rotation == Rotation::CW)
    shape_type_.rotateCw();
  else if (rotation == Rotation::ACW)
    shape_type_.rotateAcw();
  else
    std::cout << "Error: Rotate with wrong direction" << std::endl;
  k_block_shape_ = &k_block_shape_list_.at(shape_type_.getIndex());
}


IBlock::IBlock() : Block(IBlock::k_block_shape_list_) { }
OBlock::OBlock() : Block(OBlock::k_block_shape_list_) { }


// TEST CODE
void Block::printBlock()
{
  for (unsigned int i = 0; i < k_block_shape_ -> size(); i++)
  {
    for (unsigned int j = 0; j < k_block_shape_ -> at(i).size(); j++)
    {
      if (k_block_shape_->at(i).at(j))
      {
        std::cout << "0";
      }
      else
      {
        std::cout << "-";
      }
    }
    std::cout << std::endl;
  }
}
