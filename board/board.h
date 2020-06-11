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

  const bool moveABlock(Shifting::Value direction) const;
  const bool rotateABlock(Rotation::Value direction) const;

  const bool dropABlock();
  const bool dropABlockHard();

  const Position& getABlockPosition() const;
  const Block::ShapeType getABlockShapeType() const;

  void loopABlockCell(std::function<void(int, int)> function);
  void loopHBlockCell(std::function<void(int, int)> function);
  void loopWBlockCell(std::function<void(int, int)> function);

private:
  Block* active_block_; // ABlock
  Block* holded_block_; // HBlock
  std::queue<Block> waiting_blocks_; // WBlock
  std::vector<Fragment> fragments_;


  enum Wall : char {BETWEEN, RIGHT, LEFT, BOTTOM};
  const Wall getWallABlockOn() const; // If on wall, return which block.
  const bool checkABlockOnFragments() const;

  void loopBlockCell(Block& block, std::function<void(short int, short int)> function) const;
};

#endif
