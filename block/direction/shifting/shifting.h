#ifndef SHIFTING_H
#define SHIFTING_H

class Shifting
{
public:
  enum Value : char {UP, RIGHT, DOWN, LEFT};

  Shifting(const Value& value);
  const bool operator==(const Value& value) const;
  const bool operator!=(const Value& value) const;

private:
  Value value_;
};

#endif
