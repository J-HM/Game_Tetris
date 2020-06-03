#include "block.h"
#include <iostream>

Block::Block(const ShapeList& block_shape_list)
    : shape_list_(block_shape_list),
      shape_type_(),
      position_x_(0),
      position_y_(0),
      width_(block_shape_list.at(0).at(0).size()),
      height_(block_shape_list.at(0).size()),
      is_focusing_(false)
{
}

void Block::rotateBlock(Rotation rotation)
{
  if (rotation == Rotation::CW)
    shape_type_.rotateCw();
  else if (rotation == Rotation::ACW)
    shape_type_.rotateAcw();
}

void Block::setPosition(int x, int y)
{
  position_x_ = x;
  position_y_ = y;
}
