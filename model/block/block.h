#ifndef BLOCK_H
#define BLOCK_H

#include <vector>

#include "../direction/rotation/rotation.h"
#include "../direction/shifting/shifting.h"
#include "block_shape_type.h"

typedef std::vector<std::vector<bool>> BlockShape;

typedef std::vector<BlockShape> BlockShapeList;


class Block
{
public:
  Block(const BlockShapeList& k_block_shape_list);

  void rotateBlock(Rotation rotation);
  void moveBlock(Shifting shifting);
  void printBlock();

protected:
  const BlockShape* k_block_shape_;
  BlockShapeType block_shape_type_; // 0(default), 1, 2, 3

private:
  const BlockShapeList& k_block_shape_list_;
  bool is_focusing_;

  const static BlockShapeList k_i_block_shape_list_;
  const static BlockShapeList k_j_block_shape_list_;
  const static BlockShapeList k_l_block_shape_list_;
  const static BlockShapeList k_o_block_shape_list_;
};


#endif
