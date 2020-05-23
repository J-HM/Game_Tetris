#include "game_view.h"

#include <array>

using namespace sf;
using std::array;

GameView::GameView()
{
}

void GameView::openGameView() const
{
  RenderWindow window(VideoMode(500, 500), "Hello Tetris");

  RectangleShape* grid_shape = getGridShape();

  array<array<RectangleShape, 10>, 20> grids;

  for (int i = 0; i < 20; i++)
  {
    for (int j = 0; j < 10; j++)
    {
      RectangleShape grid(Vector2f(grid_length, grid_length));
      grid.setFillColor(Color(240, 240, 240));
      grid.setOutlineColor(Color(153, 153, 153));
      grid.setOutlineThickness(1.0);
      grid.setPosition(grids_offset_x + j * grid_length, grids_offset_y + i * grid_length);
      grids[i][j] = grid;
    }
  }

  while (window.isOpen())
  {
    Event event;
    while (window.pollEvent(event))
    {
      if (event.type == Event::Closed)
        window.close();
    }

    window.clear(Color(211, 211, 211));
    window.draw(*grid_shape);

    for (auto& grid_line : grids)
      for (auto& grid : grid_line)
        window.draw(grid);

    window.display();
  }

  delete grid_shape;
}


RectangleShape* GameView::getGridShape() const
{
  RectangleShape* grid_shape = new RectangleShape(Vector2f(200, 400));
  grid_shape->setFillColor(Color(255, 255, 255));
  grid_shape->setPosition(grids_offset_x, grids_offset_y);
  return grid_shape;
}
