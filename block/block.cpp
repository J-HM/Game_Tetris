#include "block.h"


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

void Block::swapBlock(Block* block)
{
  //TODO implement
}

void Block::rotateBlock(Rotation rotation)
{
  if (rotation == Rotation::CW)
    shape_type_.rotateCw();
  else if (rotation == Rotation::ACW)
    shape_type_.rotateAcw();
}

void Block::moveBlock(const Shifting shifting)
{

  if (shifting == Shifting::RIGHT)
  {
    std::cout << "In shifting function :right " << std::endl;
    position_x_++;
  }
  else if (shifting == Shifting::LEFT)
  {
    std::cout << "In shifting function :right " << std::endl;
    position_x_--;
  }
}

void Block::setPosition(int x, int y)
{
  position_x_ = x;
  position_y_ = y;
}

int Block::getPositionX()
{
  return position_x_;
}

int Block::getPositionY()
{
  return position_y_;
}
