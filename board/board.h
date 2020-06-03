#ifndef BOARD_H
#define BOARD_H

#include <array>
#include "../block/block.h"

typedef std::array<std::array<bool, 10>, 20> Grids;

class Board
{
public:
  Board();

  static const int board_width;
  static const int board_height;

private:
  Grids grids_;
  Block active_block_;

};

#endif
