#ifndef GAME_VIEW_H
#define GAME_VIEW_H

#include <array>
#include <SFML/Graphics.hpp>

#include "../board/board.h"


class GameView
{
public:
  static const int k_grid_length = 20;
  static const int k_grids_offset_x = 150;
  static const int k_grids_offset_y = 50;

public:
  GameView();
  ~GameView();

  void openGameView();

private:
  void drawBoard() const;

  sf::RenderWindow* game_window_;
  Board* game_board_;
  bool is_paused_;
};

#endif
