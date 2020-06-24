#ifndef ROTAION_HPP
#define ROTAION_HPP

class Rotation
{
public:
  enum Value: char {CW, ACW};

  Rotation(const Value& value);
  const bool operator==(const Value& value) const;
  const bool operator!=(const Value& value) const;

private:
  Value value_;
};

#endif
