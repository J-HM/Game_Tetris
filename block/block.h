#ifndef BLOCK_H
#define BLOCK_H

#include <iostream> // for test code
#include <vector>
#include <map>

#include "direction/rotation/rotation.h"
#include "direction/shifting/shifting.h"
#include "shape_type/shape_type.h"

class Block;

typedef std::vector<std::vector<std::vector<bool>>> ShapeList;

class Block
{
public:
  enum Shape: char {X, I, J, L, O}; // X: empty

  const static std::map<Shape, const ShapeList&> shpae_list_table_;
  const static ShapeList i_shape_list_;
  const static ShapeList j_shape_list_;
  const static ShapeList l_shape_list_;
  const static ShapeList o_shape_list_;

  Block(const Shape& shape);

  const Shape& getShape() const;
  const ShapeType& getShapeType() const;
  void swapBlock(Block* block);
  void rotateBlock(Rotation rotation);
  void moveBlock(Shifting shifting);
  void setPosition(int x, int y);
  int getPositionX();
  int getPositionY();

  // test code //
  void printInfo()
  {
    switch (shape_)
    {
      case I:
      {
        std::cout << "Shape: I" << std::endl;
        break;
      }
      case J:
      {
        std::cout << "Shape: J" << std::endl;
        break;
      }
      case L:
      {
        std::cout << "Shape: L" << std::endl;
        break;
      }
      case O:
      {
        std::cout << "Shape: O" << std::endl;
        break;
      }
      default:
      {
        std::cout << "Error: wrong shape" << std::endl;
      }
    }
    std::cout << "Shape type: " << shape_type_.getIndex() << std::endl;
    std::cout << "X:" << position_x_ << " Y: " << position_y_ << std::endl;
    std::cout << std::endl;
  }
  // test code //

private:
  ShapeType shape_type_; // 0(default), 1, 2, 3
  short int position_x_, position_y_;
  const Shape shape_;
  bool is_focusing_;
};


#endif
