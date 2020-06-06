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
  GameView();
  ~GameView();

  void openGameView(std::string title);

private:
  void drawDefaultBackground(sf::RenderWindow& window) const;

  Board* board_;
  bool is_paused_;
};

#endif
