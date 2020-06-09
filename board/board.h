#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <functional>
#include "../block/block.h"
#include "fragment/fragment.h"

class Board
{
public:
  static const int board_width_;
  static const int board_height_;

  Board();
  ~Board();

  void holdActiveBlock();
  void moveActiveBlockRight();
  void moveActiveBlockLeft();
  void rotateActiveBlockCw();
  void rotateActiveBlockAcw();
  void dropActiveBlockHard();
  void dropActiveBlockSoft();

  const int getActiveBlockPositionX() const;
  const int getActiveBlockPositionY() const;
  const Block::ShapeType getActivBlockShapeType() const;

  void doForEachBlockCell(std::function<void(int, int)> drawCell);

private:
  Block* active_block_;
  Block* holded_block_;
  std::vector<Fragment> fragments_;

  const bool isActiveBlockOut() const;
};

#endif
