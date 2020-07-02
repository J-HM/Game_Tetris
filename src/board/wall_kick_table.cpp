#include "board.hpp"


const WallKickTable Board::block_wall_kick_table = 
{
  {{0, 1}, {Position(0, 0), Position(-1, 0), Position(-1, 1), Position(0, -2), Position(-1, -2)}},
  {{1, 0}, {Position(0, 0), Position(1, 0), Position(1, -1), Position(0, 2), Position(1, 2)}},
  {{1, 2}, {Position(0, 0), Position(1, 0), Position(1, -1), Position(0, 2), Position(1, 2)}},
  {{2, 1}, {Position(0, 0), Position(-1, 0), Position(-1, 1), Position(0, -2), Position(-1, -2)}},
  {{2, 3}, {Position(0, 0), Position(1, 0), Position(1, 1), Position(0, -2), Position(1, -2)}},
  {{3, 2}, {Position(0, 0), Position(-1, 0), Position(-1, -1), Position(0, 2), Position(-1, 2)}},
  {{3, 0}, {Position(0, 0), Position(-1, 0), Position(-1, -1), Position(0, 2), Position(-1, 2)}},
  {{0, 3}, {Position(0, 0), Position(1, 0), Position(1, 1), Position(0, -2), Position(1, -2)}}
};


// const WallKickTable i_block_wall_kick_table;