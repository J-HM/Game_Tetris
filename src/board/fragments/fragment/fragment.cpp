#include "fragment.hpp"

Fragment::Fragment(Position position, Block::ShapeType shape_type)
    : position_(position),
      shape_type_(shape_type)
{
}


void Fragment::setPosition(Position position)
{
  position_ = position;
}


const Position& Fragment::getPosition() const
{
  return position_;
}

const Block::ShapeType& Fragment::getShapeType() const
{
  return shape_type_;
}