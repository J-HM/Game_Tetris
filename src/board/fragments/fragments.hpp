#ifndef FRAGMENTS_HPP
#define FRAGMENTS_HPP

#include <list>
#include <algorithm>
#include <functional>

#include "fragment/fragment.hpp"


using fragments_iterator = std::list<Fragment*>::const_iterator;

class Fragments
{
public:
  const bool isFullRow(int y) const;
  void clearRow(int y);
  void moveDownRow(int y);

  std::optional<Fragment*> getHighestFrag() const;
  
  void refreshSurfaceFrags();

  void pushBlock(Block& block);

  std::optional<Fragment*> findFragByPosition(Position position) const;

  const bool loopFrags(const std::function<bool(Fragment&, Block::ShapeType)>& function) const;
  const bool loopSurfaceFrags(const std::function<bool(Fragment&)>& function) const;

private:
  std::list<Fragment*> fragments_;
  std::list<Fragment*> surface_fragments_;
};


#endif