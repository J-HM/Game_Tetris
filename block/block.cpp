
#include "block.h"

Block::Block(const ShapeType& shape)
    : shape_index_(0),
      position_(Position(0, 0)),
      shape_type_(shape),
      is_focusing_(false)
{
}

const Block::ShapeType Block::getRandomShape(int multiple)
{
  using namespace std::chrono;
  auto now = high_resolution_clock::now();
  auto ns = duration_cast<milliseconds>(now.time_since_epoch());

  auto fractional_seconds = (ns.count() + multiple) * multiple % 4;
  // TODO give more Randomness
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

void Block::swapBlock(Block* block)
{
  //TODO implement
}

void Block::rotateBlock(Rotation direction)
{
  if (direction == Rotation::CW)
    shape_index_.rotateCw();
  else if (direction == Rotation::ACW)
    shape_index_.rotateAcw();
}

void Block::moveBlock(const Shifting direction)
{
  if (direction == Shifting::RIGHT)
    position_.x_++;
  else if (direction == Shifting::LEFT)
    position_.x_--;
  else if (direction == Shifting::UP)
    position_.y_--;
  else if (direction == Shifting::DOWN)
    position_.y_++;
}

void Block::setPosition(Position& position)
{
  position_ = position;
}

const Position& Block::getPosition() const
{
  return position_;
}

const Shape& Block::getShape() const
{
  auto& shape_list = shpae_list_map_.find(shape_type_)->second;
  auto& shape = shape_list.at(shape_index_.getIndex());
  return shape;
}

const Block::ShapeType& Block::getShapeType() const
{
  return shape_type_;
}
