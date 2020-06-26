#ifndef FRAGMENTS_HPP
#define FRAGMENTS_HPP

#include <list>
#include <functional>

#include "fragment/fragment.hpp"


using fragments_iterator = std::list<Fragment*>::const_iterator;

class Fragments
{
public:
  const bool checkLine(int y) const;
  void deleteLine(int y);

  const std::list<Fragment*>& getSurfaceFrags() const;
  void refreshSurfaceFrags();

  const Fragment getHighestFrag();

  void pushBlock(Block& block);

  const bool loopFrags(std::function<bool(Fragment&, Block::ShapeType)>& function) const;
  
private:
  std::list<Fragment*> fragments_;
  std::list<Fragment*> surface_fragments_;

  fragments_iterator findFragBy(const Position& position) const;
  const bool deleteFrag(const Position& position);
};


#endif