#ifndef BOARD_H
#define BOARD_H

#include <array>

typedef std::array<std::array<bool, 10>, 20> Grids;

class Board
{
public:
  static const int k_board_width;
  static const int k_board_height;

public:
  Board();

private:
  Grids grid;

};

#endif
