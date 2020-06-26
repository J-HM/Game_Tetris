#ifndef POSITION_HPP
#define POSITION_HPP


class Position
{
public:
  Position(int x = 0, int y = 0);

  const bool operator==(const Position& other_position) const; 

  int x_;
  int y_;
};


#endif
