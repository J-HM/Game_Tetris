#include "block.h"
#include <iostream>

Block::Block(const BlockShapeList& k_block_shape_list)
    : k_block_shape_(&k_block_shape_list.at(0)),
      block_shape_type_(0),
      k_block_shape_list_(k_block_shape_list),
      is_focusing_(false)

{ }

void Block::rotateBlock(Rotation rotation)
{
  if (rotation == Rotation::CW)
    block_shape_type_.rotateCw();
  else if (rotation == Rotation::ACW)
    block_shape_type_.rotateAcw();
  else
    std::cout << "Error: Rotate with wrong direction" << std::endl;
  k_block_shape_ = &k_block_shape_list_.at(block_shape_type_.getIndex());
}


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
