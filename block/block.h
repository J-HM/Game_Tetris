#ifndef BLOCK_H
#define BLOCK_H

#include <vector>
#include <iostream> // for test code

#include "direction/rotation/rotation.h"
#include "direction/shifting/shifting.h"
#include "shape_type.h"


typedef std::vector<std::vector<bool>> Shape;
typedef std::vector<Shape> ShapeList;



class Block
{
public:
  Block(const ShapeList& k_block_shape_list);

  void rotateBlock(Rotation rotation);
  void moveBlock(Shifting shifting);
  void setPosition(int x, int y);

  const static ShapeList i_shape_list_;
  const static ShapeList j_shape_list_;
  const static ShapeList l_shape_list_;
  const static ShapeList o_shape_list_;

  // test code //
  void printInfo()
  {
    std::cout << "x:" << position_x_ << " y: " << position_y_ << std::endl;
    std::cout << "width:" << width_ << " height: " << height_ << std::endl;
  }
  // test code //

private:
  const ShapeList& shape_list_;
  ShapeType shape_type_; // 0(default), 1, 2, 3

  int position_x_, position_y_;
  int width_, height_;
  bool is_focusing_;
};


#endif
