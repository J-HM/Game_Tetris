#ifndef SHIFTING_H
#define SHIFTING_H

class Shifting
{
public:
  enum Value : int {UP, RIGHT, DOWN, LEFT};

  Shifting(const Value& value);
  const bool operator==(Shifting& location) const;
  const bool operator!=(Shifting& location) const;

private:
  Value value_;
};

#endif
