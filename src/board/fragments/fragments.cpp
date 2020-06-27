#include "fragments.hpp"
#include "../board.hpp"


const bool Fragments::isFullRow(int y) const
{
  int frag_count = 0;
  for (auto iterator = fragments_.begin(); iterator != fragments_.end(); iterator++)
  {
    int frag_position_y = (*iterator)->getPosition().y_;
    if (frag_position_y < y) continue;
    if (frag_position_y > y) break;
    if (frag_position_y == y) frag_count++;
    if (frag_count == Board::ab_zone_width_) return true;
  }
  return false;
}

void Fragments::clearRow(int y)
{
  fragments_.remove_if([&y](const Fragment* fragment)
  {
    if (fragment->getPosition().y_ == y) return true;
    else return false;
  });
}

void Fragments::moveDownRow(int y)
{
  for (auto iterator = fragments_.begin(); iterator != fragments_.end(); iterator++)
  {
    int frag_position_x = (*iterator)->getPosition().x_;
    int frag_position_y = (*iterator)->getPosition().y_;
    if (frag_position_y < y) 
      continue;
    if (frag_position_y > y)
      break;
    if (frag_position_y == y)
      (*iterator)->setPosition(Position(frag_position_x, frag_position_y + 1));
  }
}


const Fragment& Fragments::getHighestFrag() const
{
  return **(fragments_.cbegin());
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
    Fragment* fragment = new Fragment(Position(position_x, position_y), shape_type);
    if (fragments.empty()) 
    {
      fragments.push_back(fragment);
      return false;
    }
    fragments_iterator iterator = fragments.begin();
    while (iterator != fragments.end())
    {
      if (position_y < (*iterator)->getPosition().y_) break;
      iterator++;
    }
    fragments.insert(iterator, fragment);
    return false;
  });
}


const bool Fragments::loopFrags(const std::function<bool(Fragment&, Block::ShapeType)>& function) const
{
  bool result = false;
  for (const auto& fragment : fragments_)
  {
    result = function(*fragment, fragment->getShapeType());
    if (result) break; // If function returns true, this loop break.
  }
  return result;
}

const bool Fragments::loopSurfaceFrags(const std::function<bool(Fragment&)>& function) const
{
  bool result = false;
  for (const auto& fragment : surface_fragments_)
  {
    result = function(*fragment);
    if (result) break; // If function returns true, this loop break.
  }
  return result;
}