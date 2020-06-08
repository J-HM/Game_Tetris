#include "shape_index.h"


ShapeIndex::ShapeIndex(short int shape_index)
    : shape_index_(shape_index)
{
}

void ShapeIndex::rotateCw()
{
  shape_index_++;
  if (shape_index_ > 3) shape_index_ = 0;
}

void ShapeIndex::rotateAcw()
{
  shape_index_--;
  if (shape_index_ < 0) shape_index_ = 3;
}

const short int& ShapeIndex::getIndex() const
{
  return shape_index_;
}
