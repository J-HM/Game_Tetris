#include "shape_type.h"


ShapeType::ShapeType(short int shape_type)
    : shape_type_(shape_type)
{
}

void ShapeType::rotateCw()
{
  shape_type_++;
  if (shape_type_ > 3) shape_type_ = 0;
}

void ShapeType::rotateAcw()
{
  shape_type_--;
  if (shape_type_ < 0) shape_type_ = 3;
}

const short int& ShapeType::getIndex() const
{
  return shape_type_;
}
