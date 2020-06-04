#ifndef BOARD_H
#define BOARD_H

#include <array>
#include "../block/block.h"

typedef std::array<std::array<bool, 10>, 20> Grids;

class Board
{
public:
  static const int board_width;
  static const int board_height;

  Board();
  ~Board();

  void holdBlock();
  void moveBlockRight();
  void moveBlockLeft();
  void rotateBlockCW();
  void rotateBlockACW();
  void dropBlockHard();
  void dropBlockSoft();

private:
  Grids grids_;
  Block* active_block_;
  Block* holded_block_;
};

#endif
