#include "game_view.h"

using namespace sf;
using std::array;

GameView::GameView(std::string title)
    : window_(new RenderWindow(VideoMode(500, 500), title, Style::Close)),
      board_(new Board()),
      is_paused_(false)
{
}

GameView::~GameView()
{
  delete window_;
  delete board_;
}

void GameView::openGameView()
{
  while (window_->isOpen())
  {
    // event process //
    Event event;
    while (window_->pollEvent(event))
    {
      if (event.type == Event::Closed)
        window_->close();
      if (event.type == Event::KeyPressed)
      {
        if (event.key.code == Keyboard::Escape)
          is_paused_ = !is_paused_; // Pause / Play
        else if (event.key.code == Keyboard::Z)
          board_->rotateBlockACW(); // Rotate ACW
        else if (event.key.code == Keyboard::C)
          board_->holdBlock();      // Hold Block
        else if (event.key.code == Keyboard::Space)
          board_->dropBlockHard();  // Hard Drop
        else if (event.key.code == Keyboard::Up)
          board_->rotateBlockCW();  // Rotate CW
        else if (event.key.code == Keyboard::Right)
          board_->moveBlockRight(); // Move Right
        else if (event.key.code == Keyboard::Down)
          board_->dropBlockSoft();  // Soft Drop
        else if (event.key.code == Keyboard::Left)
          board_->moveBlockLeft();  // Move Left
      }
    }
    // board precess //

    // draw precess //
    window_->clear(Color(221, 221, 221));

    if (is_paused_)
    {
      continue;
    }

    drawBoard();
    window_->display();
  }
}

void GameView::drawBoard() const
{
  for (int i = 0; i < Board::board_height; i++)
  {
    for (int j = 0; j < Board::board_width; j++)
    {
      RectangleShape grid(Vector2f(grid_length, grid_length));
      grid.setFillColor(Color(240, 240, 240));
      grid.setOutlineColor(Color(153, 153, 153));
      grid.setOutlineThickness(1.0);
      int position_x = grids_offset_x + j * grid_length;
      int position_y = grids_offset_y + i * grid_length;
      grid.setPosition(position_x, position_y);
      window_->draw(grid);
    }
  }

//  for (int i = 0; i < board_->active_block_->width_; i++)
//  {
//
//  }
//  board_->active_block_->getPositionX();
//  board_->active_block_->getPositionY();
}
