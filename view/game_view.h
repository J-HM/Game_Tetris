#ifndef GAME_VIEW_H
#define GAME_VIEW_H

#include <SFML/Graphics.hpp>


class GameView
{
private:

public:
  GameView();

  void openGameView() const;

private:
  sf::RectangleShape* getGridShape() const;


  static const int grid_length = 20;
  static const int grids_offset_x = 150;
  static const int grids_offset_y = 50;
};

#endif
