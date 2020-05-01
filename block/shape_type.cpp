#include "shape_type.h"

ShapeType::ShapeType(int shape_type)
    : shape_type_(shape_type)
{
}

void ShapeType::rotateCw()
{
  shape_type_++;
  if (shape_type_ > 4) shape_type_ = 0;

}

void ShapeType::rotateAcw()
{
  shape_type_--;
  if (shape_type_ < 0) shape_type_ = 3;
}

const int& ShapeType::getIndex() const
{
  return shape_type_;
}
