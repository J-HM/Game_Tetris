#include "point.h"

Point::Point() {}
Point::Point(int _x, int _y) : x(_x), y(_y) {}

Point& Point::operator=(Point& _point)
{
  x = _point.x;
  y = _point.y;
  return *this;
}

Point& Point::operator--()
{
  x--;
  y--;
  return *this;
}

int Point::getX()
{
  return x;
}

int Point::getY()
{
  return y;
}
