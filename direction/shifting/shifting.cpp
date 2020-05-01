#include "../shifting/shifting.h"

Shifting::Shifting(const Value& value)
    : value_(value)
{
}

const bool Shifting::operator==(Shifting& location) const
{
  return value_ == location.value_;
}

const bool Shifting::operator!=(Shifting& location) const
{
  return value_ != location.value_;
}
