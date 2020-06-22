#ifndef FRAGMENT_H
#define FRAGMENT_H

#include "../../position/position.h"
#include "../block.h"

class Fragment
{
public:
  Fragment(Position position, Block::ShapeType shpae_type);

  void deleteLine();
  void putInBlock(Block block);

private:
  Position position_;

};



#endif
