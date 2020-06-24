#ifndef GAME_VIEW_HPP
#define GAME_VIEW_HPP

#include <array>
#include <SFML/Graphics.hpp>

#include "../board/board.hpp"


class GameView
{
public:
  static const sf::RectangleShape getCell(Block::ShapeType shape);

  static const int cell_length_ = 25;
  static const int window_width_ = 600;
  static const int window_height_ = 600;
  static const int ab_zone_offset_x_ = 175;
  static const int ab_zone_offset_y_ = 50;
  static const int hb_zone_offset_x_ = 50;
  static const int hb_zone_offset_y_ = 50;
  static const int wb_zone_offset_x_ = 450;
  static const int wb_zone_offset_y_ = 50;

public:
  GameView(std::string title);
  ~GameView();

  void openView() const;

private:
  void drawABZone() const; // draw active block background 
  void drawHBZone() const; // draw holding block background
  void drawWBZone() const; // draw waiting blocks background

  void drawAB() const;
  void drawHB() const;
  void drawWB() const;

  void drawFragment() const;

  sf::RenderWindow* window_;
  Board* board_;
};

#endif
