#include "../shifting/shifting.h"

Shifting::Shifting(const Value& value)
    : value_(value)
{
}

const bool Shifting::operator==(const Value& value) const
{
  return value_ == value;
}

const bool Shifting::operator!=(const Value& value) const
{
  return value_ != value;
}
