#include "block_shape_type.h"

BlockShapeType::BlockShapeType(int shape_type)
    : shape_type_(shape_type)
{
}

void BlockShapeType::rotateCw()
{
  shape_type_++;
  if (shape_type_ > 4) shape_type_ = 0;

}

void BlockShapeType::rotateAcw()
{
  shape_type_--;
  if (shape_type_ < 0) shape_type_ = 3;
}

const int& BlockShapeType::getIndex() const
{
  return shape_type_;
}
