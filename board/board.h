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

  void holdActiveBlock();
  void moveActiveBlockRight();
  void moveActiveBlockLeft();
  void rotateActiveBlockCw();
  void rotateActiveBlockAcw();
  void dropActiveBlockHard();
  void dropActiveBlockSoft();

  int getActiveBlockPositionX();
  int getActiveBlockPositionY();

  void doForEachBlockCell(std::function<void(int, int)> drawCell);

private:
  Block* active_block_;
  Block* holded_block_;
  std::vector<Fragment> fragments_;
};

#endif
