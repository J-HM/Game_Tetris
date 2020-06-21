#ifndef BLOCK_H
#define BLOCK_H

#include <iostream> // for test code
#include <random>
#include <chrono>
#include <vector>
#include <map>

#include "position/position.h"
#include "direction/rotation/rotation.h"
#include "direction/shifting/shifting.h"
#include "shape_index/shape_index.h"


using Shape = std::vector<std::vector<bool>>;
using ShapeList = std::vector<std::vector<std::vector<bool>>>;

class Block
{
public:
  enum ShapeType: char {EMPTY, I, J, L, O};

  const static ShapeType getRandomShape(int multiple = 1);
  const static std::map<ShapeType, const ShapeList&> shpae_list_map_;

private:
  const static ShapeList empty_shape_list_;
  const static ShapeList i_shape_list_;
  const static ShapeList j_shape_list_;
  const static ShapeList l_shape_list_;
  const static ShapeList o_shape_list_;

public:
  Block(const ShapeType& shape);

  void swapBlock(Block* block);
  void rotateBlock(Rotation direction);
  void moveBlock(Shifting direction);

  const Shape& getShape() const;
  const ShapeType& getShapeType() const;
  const Position& getPosition() const;

  void setPosition(Position& position);

  void printInfo() const
  {
    switch (shape_type_)
    {
      case I:
        std::cout << "Shape: I" << std::endl;
        break;
      case J:
        std::cout << "Shape: J" << std::endl;
        break;
      case L:
        std::cout << "Shape: L" << std::endl;
        break;
      case O:
        std::cout << "Shape: O" << std::endl;
        break;
      case EMPTY:
        std::cout << "Empty Shape" << std::endl;
        break;
      default:
        std::cout << "Error: wrong shape" << std::endl;
    }
    std::cout << "Shape Index: " << shape_index_.getIndex() << std::endl;
    std::cout << "X:" << position_.x_ << " Y: " << position_.y_ << std::endl;
    std::cout << std::endl;
  }

private:
  ShapeIndex shape_index_; // 0(default), 1, 2, 3
  Position position_;
  const ShapeType shape_type_;
  bool is_focusing_;
};


#endif
