#ifndef GAME_VIEW_H
#define GAME_VIEW_H

#include <array>
#include <SFML/Graphics.hpp>

#include "../board/board.h"


class GameView
{
public:
  static const sf::RectangleShape getCell(Block::ShapeType shape);

  static const int cell_length_ = 30;
  static const int window_width_ = 700;
  static const int window_height_ = 700;
  static const int grid_offset_x_ = 100;
  static const int grid_offset_y_ = 50;

public:
  GameView(std::string title);
  ~GameView();

  void openGameView() const;

private:
  void drawBackground() const;
  void drawActiveBlock() const;

  sf::RenderWindow* window_;
  Board* board_;
};

#endif
