#ifndef FRAGMENT_H
#define FRAGMENT_H

#include "../../position/position.h"
#include "../../block/block.h"


class Fragment
{
public:
  Fragment(Position position, Block::ShapeType shpae_type);
  
  void setPosition(Position position);

  const Position& getPosition() const;
  const Block::ShapeType& getShapeType() const;
  
private:
  Position position_;
  const Block::ShapeType shape_type_;

};



#endif
