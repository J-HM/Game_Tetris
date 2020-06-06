#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <functional>
#include "../block/block.h"
#include "fragment/fragment.h"

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
  void rotateBlockCw();
  void rotateBlockAcw();
  void dropBlockHard();
  void dropBlockSoft();

  void drawActiveBlock(std::function<void(int, int)> drawCell);

private:
  Block* active_block_;
  Block* holded_block_;
  std::vector<Fragment> fragments_;
};

#endif
