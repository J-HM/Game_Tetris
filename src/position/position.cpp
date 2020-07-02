#include "position.hpp"


Position::Position(int x, int y)
    : x_(x),
      y_(y)
{
}


const bool Position::operator==(const Position& other_position) const
{
  return other_position.x_ == x_ && other_position.y_ == y_;
}

const Position Position::operator+(const Position& other_position) const
{
  return Position(x_ + other_position.x_, y_ + other_position.y_);
}