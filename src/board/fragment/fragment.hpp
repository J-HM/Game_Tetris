#ifndef FRAGMENT_HPP
#define FRAGMENT_HPP

#include "../../position/position.hpp"
#include "../../block/block.hpp"


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
