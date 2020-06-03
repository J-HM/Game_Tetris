#include "board.h"

const int Board::board_width = 10;
const int Board::board_height = 20;

Board::Board()
    : grids_({}), // initialize gird to zero
      active_block_(Block::l_shape_list_)
{
  active_block_.printInfo();
}
