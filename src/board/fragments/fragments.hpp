#ifndef FRAGMENTS_HPP
#define FRAGMENTS_HPP

#include <vector>

#include "fragment/fragment.hpp"

class Fragments
{
public:
  Fragments();

  void checkLine(int y) const;
  void deleteLine(int y);
  void putInBlock();

private:
  std::vector<Fragment*> fragments_;
  
};


#endif