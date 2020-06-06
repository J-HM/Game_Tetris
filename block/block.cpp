#include "block.h"


Block::Block(const Shape& shape)
    : shape_(shape),
      shape_type_(0),
      position_x_(5),
      position_y_(0),
      is_focusing_(false)
{
}

const Block::Shape& Block::getShape() const
{
  return shape_;
}

const ShapeType& Block::getShapeType() const
{
  return shape_type_;
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
    position_x_++;
  else if (shifting == Shifting::LEFT)
    position_x_--;
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
