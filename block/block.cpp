
#include "block.h"

Block::Block(const Shape& shape)
    : shape_type_(0),
      position_x_(5),
      position_y_(0),
      shape_(shape),
      is_focusing_(false)
{
}

const Block::Shape Block::getRandomShape()
{
  using namespace std::chrono;
  high_resolution_clock::time_point now = high_resolution_clock::now();
  milliseconds ms = duration_cast<milliseconds>(now.time_since_epoch());
  std::size_t fractional_seconds = ms.count() % 4;
  std::cout << fractional_seconds << std::endl;
  switch (fractional_seconds)
  {
    case 0:
      return Block::I;
    case 1:
      return Block::J;
    case 2:
      return Block::L;
    case 3:
      return Block::O;
    default:
      return Block::EMPTY;
  }
  //return distribution(generator);
//  return Block::I;
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
