#include "game_view.h"

using namespace sf;
using std::array;

GameView::GameView(std::string title)
    : window_(new RenderWindow(VideoMode(500, 500), title, Style::Close)),
      board_(new Board())
{
}

GameView::~GameView()
{
  delete window_;
  delete board_;
}

void GameView::openGameView()
{
  bool is_paused;
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
          is_paused = !is_paused; // Pause / Play
        else if (event.key.code == Keyboard::Z)
          board_->rotateActiveBlockAcw(); // Rotate ACW
        else if (event.key.code == Keyboard::C)
          board_->holdActiveBlock();      // Hold Block
        else if (event.key.code == Keyboard::Space)
          board_->dropActiveBlockHard();  // Hard Drop
        else if (event.key.code == Keyboard::Up)
          board_->rotateActiveBlockCw();  // Rotate CW
        else if (event.key.code == Keyboard::Right)
          board_->moveActiveBlockRight(); // Move Right
        else if (event.key.code == Keyboard::Down)
          board_->dropActiveBlockSoft();  // Soft Drop
        else if (event.key.code == Keyboard::Left)
          board_->moveActiveBlockLeft();  // Move Left
      }
    }
    // board precess //

    // draw precess //
    window_->clear(Color(221, 221, 221));
    drawBackground();

    if (is_paused)
    {
      continue;
    }

    drawActiveBlock();

    window_->display();
  }
}

void GameView::drawActiveBlock() const
{
  RectangleShape grid(Vector2f(grid_length, grid_length));
  grid.setFillColor(Color(108, 18, 248));
  grid.setOutlineColor(Color(123, 123, 123));
  grid.setOutlineThickness(0.8);
  int block_position_x = board_->getActiveBlockPositionX();
  int block_position_y = board_->getActiveBlockPositionY();

  board_->doForEachBlockCell([&] (int x, int y) {
    int position_x = grids_offset_x + (block_position_x + x) * grid_length;
    int position_y = grids_offset_y + (block_position_y + y) * grid_length;
    grid.setPosition(position_x, position_y);
    window_->draw(grid);
  });
}

void GameView::drawBackground() const
{
  RectangleShape grid(Vector2f(grid_length, grid_length));
  grid.setFillColor(Color(248, 248, 248));
  grid.setOutlineColor(Color(153, 153, 153));
  grid.setOutlineThickness(1.0);
  for (int i = 0; i < Board::board_height; i++)
  {
    for (int j = 0; j < Board::board_width; j++)
    {
      int position_x = grids_offset_x + j * grid_length;
      int position_y = grids_offset_y + i * grid_length;
      grid.setPosition(position_x, position_y);
      window_->draw(grid);
    }
  }
}
