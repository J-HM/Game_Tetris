#include "rotation.h"

Rotation::Rotation(const Value& value)
    : value_(value)
{
}

const bool Rotation::operator==(const Value& value) const
{
  return value_ == value;
}

const bool Rotation::operator!=(const Value& value) const
{
  return value_ != value;
}
