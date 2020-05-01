#ifndef BLOCK_H
#define BLOCK_H

#include <vector>

#include "../direction/rotation/rotation.h"
#include "../direction/shifting/shifting.h"
#include "shape_type.h"

using std::vector;

class Block
{
public:
  Block(const vector<vector<vector<bool>>>& k_block_shape_list);

  void rotateBlock(Rotation rotation);
  void moveBlock(Shifting shifting);
  void printBlock();

protected:
  const vector<vector<bool>>* k_block_shape_;
  ShapeType shape_type_;

private:
  const vector<vector<vector<bool>>>& k_block_shape_list_;
  bool is_focusing_;
};


class IBlock : public Block
{
public:
  const static vector<vector<vector<bool>>> k_block_shape_list_;
  IBlock();
};

class OBlock : public Block
{
public:
  const static vector<vector<vector<bool>>> k_block_shape_list_;
  OBlock();
};


#endif
