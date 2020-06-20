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

  static const int wb_count_ = 3;
  static const int ab_zone_width_ = 10;
  static const int ab_zone_height_ = 20;
  static const int hb_zone_width_ = 4;
  static const int hb_zone_height_ = 4;
  static const int wb_zone_width_ = 4;
  static const int wb_zone_height_ = 15;

  Board();
  ~Board();

  void holdAB();

  const bool moveAB(Shifting::Value direction) const;
  const bool rotateAB(Rotation::Value direction) const;

  const bool dropAB();
  const bool dropABHard();

  const Position& getABPosition() const;
  const Block::ShapeType getABShapeType() const;
  const Block::ShapeType getHBShapeType() const;
  const Block::ShapeType getWBShapeType(int index) const;

  void loopABCell(std::function<void(int, int)> function);
  void loopHBCell(std::function<void(int, int)> function);
  void loopWBCell(std::function<void(int, int)> function);

private:
  Block* active_block_; // AB
  Block* holded_block_; // HB
  std::vector<Block*> waiting_blocks_; // WB
  std::vector<Fragment> fragments_;


  enum Wall : char {BETWEEN, RIGHT, LEFT, BOTTOM};
  const Wall getWallABlockOn() const; // If on wall, return which block.
  const bool checkABlockOnFragments() const;

  void loopBlockCell(Block& block, std::function<void(short int, short int)> function) const;
};

#endif
