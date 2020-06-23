#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <queue>
#include <algorithm>
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
  
  void swapABwithHB();
  void moveAB(Shifting::Value direction);
  void rotateAB(Rotation::Value direction) const;
  void dropABHard();

  const Position& getABPosition() const;
  const Block::ShapeType getABShapeType() const;
  const Block::ShapeType getHBShapeType() const;
  const Block::ShapeType getWBhapeType(int index) const;

  void loopABCells(std::function<bool(int, int)> function) const;
  void loopHBCells(std::function<bool(int, int)> function) const;
  void loopWBCells(int index, std::function<bool(int, int)> function) const;
  void loopFragments(std::function<bool(Block::ShapeType, int, int)> function) const;

  void popWBToAB();

  const bool getIsABFalling() const;
  const bool getIsSwapped() const;

  void putABtoFragments();
  const bool checkFragmentLine() const;
  void deleteFragmentLine(short int y);

private:
  Block* active_block_;               // AB
  Block* holded_block_;               // HB
  std::deque<Block*> waiting_blocks_; // WB
  std::vector<Fragment*> fragments_;

  bool is_ab_falling_;
  bool is_swapped_;

  const bool isABOnLeftWall() const;
  const bool isABOnRightWall() const;
  const bool isABOnBottomWall() const;

  const bool isABOnFragments() const;

  const bool loopBlockCell(Block& block, std::function<bool(int, int)> function) const;
};

#endif
