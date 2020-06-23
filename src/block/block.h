#ifndef BLOCK_H
#define BLOCK_H

#include <iostream> // for test code
#include <random>
#include <chrono>
#include <vector>
#include <map>

#include "../position/position.h"
#include "../direction/rotation/rotation.h"
#include "../direction/shifting/shifting.h"
#include "shape_index/shape_index.h"


using Shape = std::vector<std::vector<bool>>;
using ShapeList = std::vector<std::vector<std::vector<bool>>>;

class Block
{
public:
  enum ShapeType: char {EMPTY, I, J, L, O, S, T, Z};

  const static ShapeType getRandomShape();
  const static std::map<ShapeType, const ShapeList&> shpae_list_map_;

private:
  const static short int shape_type_count_ = 7;
  const static ShapeList empty_shape_list_; // Declared in shape_list.cpp
  const static ShapeList i_shape_list_;
  const static ShapeList j_shape_list_;
  const static ShapeList l_shape_list_;
  const static ShapeList o_shape_list_;
  const static ShapeList s_shape_list_;
  const static ShapeList t_shape_list_;
  const static ShapeList z_shape_list_;

public:
  Block(const ShapeType& shape);

  void rotateBlock(Rotation direction);
  void moveBlock(Shifting direction);

  const Shape& getShape() const;
  const ShapeType& getShapeType() const;
  const Position& getPosition() const;
  const int getContainerWidth() const;
  const int getContainerHeight() const;

  void setPosition(Position&& position);
  void setPosition(short int x, short int y);

  void printStatus() const;

private:
  ShapeIndex shape_index_; // 0(default), 1, 2, 3
  Position position_;
  const ShapeType shape_type_;
  bool is_focusing_;
};


#endif
