#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

#include "../block/block.hpp"
#include "fragments/fragments.hpp"


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

  void loopABCells(const std::function<bool(int, int)>& function) const;
  void loopHBCells(const std::function<bool(int, int)>& function) const;
  void loopWBCells(int index, const std::function<bool(int, int)>& function) const;
  void loopFrags(std::function<bool(Fragment&, Block::ShapeType)>&& function) const;

  void popWBToAB();

  const bool getIsABFalling() const;
  const bool getIsSwapped() const;

  void pushABtoFrags();
  void checkFrags();

private:
  Block* active_block_;               // AB
  Block* holded_block_;               // HB
  std::deque<Block*> waiting_blocks_; // WB
  Fragments fragments_;  // Frags

  bool is_ab_falling_;
  bool is_swapped_;

  const bool isABOnLeftWall() const;
  const bool isABOnRightWall() const;
  const bool isABOnBottomWall() const;

  const bool isABOnFrags() const;

};


#endif