#ifndef GAME_VIEW_H
#define GAME_VIEW_H

#include <array>
#include <SFML/Graphics.hpp>

#include "../board/board.h"


class GameView
{
public:
  static const int grid_length = 20;
  static const int grids_offset_x = 150;
  static const int grids_offset_y = 50;

public:
  GameView(std::string title);
  ~GameView();

  void openGameView();

private:
  void drawBackground() const;
  void drawActiveBlock() const;

  sf::RenderWindow* window_;
  Board* board_;
};

#endif
