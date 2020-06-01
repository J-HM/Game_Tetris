#include "game_view.h"


using namespace sf;
using std::array;

GameView::GameView()
    : game_window_(new RenderWindow(VideoMode(500, 500), "Hello Tetris")),
      game_board_(new Board()),
      is_paused_(false)
{
}

GameView::~GameView()
{
  delete game_window_;
  delete game_board_;
}

void GameView::openGameView()
{
  while (game_window_->isOpen())
  {
    // event process //
    Event event;
    while (game_window_->pollEvent(event))
    {
      if (event.type == Event::Closed)
        game_window_->close();

      if (event.type == Event::KeyPressed)
        if (event.key.code==Keyboard::Escape)
          is_paused_ = !is_paused_;                  // Pause / Play
//        else if (event.key.code==Keyboard::Z)
//          rotate=true;                             // Rotate ACW
//        else if (event.key.code==Keyboard::C)
//          rotate=true;                             // Hold
//        else if (event.key.code==Keyboard::Space)
//          rotate=true;                             // Hard Drop
//        else if (event.key.code==Keyboard::Up)
//          dx=-1;                                   // Rotate CW
//        else if (event.key.code==Keyboard::Right)
//          dx=-1;                                   // Move Right
//        else if (event.key.code==Keyboard::Down)
//          dx=-1;                                   // Soft Drop
//        else if (event.key.code==Keyboard::Left)
//          dx=1;                                    // Move Left
    }

    // draw precess //
    game_window_->clear(Color(211, 211, 211));

    if (is_paused_)
    {
      continue;
    }

    drawBoard();
    game_window_->display();
  }
}

void GameView::drawBoard() const
{
  for (int i = 0; i < Board::k_board_height; i++)
  {
    for (int j = 0; j < Board::k_board_width; j++)
    {
      RectangleShape grid(Vector2f(k_grid_length, k_grid_length));
      grid.setFillColor(Color(240, 240, 240));
      grid.setOutlineColor(Color(153, 153, 153));
      grid.setOutlineThickness(1.0);
      grid.setPosition(k_grids_offset_x + j * k_grid_length, k_grids_offset_y + i * k_grid_length);
      game_window_->draw(grid);
    }
  }
}
