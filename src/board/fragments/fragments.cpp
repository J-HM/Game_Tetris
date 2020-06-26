#include "fragments.hpp"
#include "../board.hpp"


const bool Fragments::checkLine(int y) const
{
  for (int x = 0; x < Board::ab_zone_width_; x++)
  {
    Position position(x, y);
    if (findFragBy(position) == fragments_.end()) 
      return false;
  }
  return true;
}

void Fragments::deleteLine(int y)
{
  for (int x = 0; x < Board::ab_zone_width_; x++)
  {
    deleteFrag(Position(x, y));
  }
}


const std::list<Fragment*>& Fragments::getSurfaceFrags() const
{
  return surface_fragments_;
}

void Fragments::refreshSurfaceFrags()
{
  
}


void Fragments::pushBlock(Block& block)
{
  const auto& shape_type = block.getShapeType();
  const auto& position = block.getPosition();
  block.loopCell([&fragments = fragments_, &shape_type, &position](int x, int y) 
  {
    int position_x = position.x_ + x;
    int position_y = position.y_ + y;
    fragments.push_back(new Fragment(Position(position_x, position_y), shape_type));
    return false; // Returning false makes loop keep working
  });
}


const bool Fragments::loopFrags(
  std::function<bool(Fragment&, Block::ShapeType)>& function) const
{
  bool result = false;
  for (const auto& fragment : fragments_)
  {
    result = function(*fragment, fragment->getShapeType());
    if (result) break; // If function returns true, this loop break.
  }
  return result;
}


fragments_iterator Fragments::findFragBy(const Position& position) const
{
  for(fragments_iterator iterator = fragments_.begin(); iterator != fragments_.end(); iterator++)
    if (position == (*iterator)->getPosition())
      return iterator;
  return fragments_.end();
}


const bool Fragments::deleteFrag(const Position& position)
{
  fragments_iterator iterator = findFragBy(position);
  if (iterator != fragments_.end())
    return false;
  fragments_.erase(iterator);
  return true;
}