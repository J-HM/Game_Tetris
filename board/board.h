#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <queue>
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

  void holdABlock();

  void moveABlockRight();
  void moveABlockLeft();

  void rotateABlockCw();
  void rotateABlockAcw();

  const bool dropABlockNormal();
  const bool dropABlockSoft();
  const bool dropABlockHard();

  const int getABlockPositionX() const;
  const int getABlockPositionY() const;
  const Block::ShapeType getABlockShapeType() const;

  void doForEachABlockCell(std::function<void(int, int)> drawCell);

private:
  Block* active_block_; // ABlock
  Block* holded_block_; // HBlock
  std::queue<Block> waiting_blocks_; // WBlock
  std::vector<Fragment> fragments_;


  enum Wall : char {BETWEEN, RIGHT, LEFT, BOTTOM};
  const Wall getWallABlockOn() const; // If on wall, return which block.
  const bool checkABlockOnFragments() const;
};

#endif
