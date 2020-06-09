#include "game_view.h"

using namespace sf;
using std::array;

GameView::GameView(std::string title)
    : window_(new RenderWindow(VideoMode(window_width_, window_height_), title, Style::Close)),
      board_(new Board())
{
}

GameView::~GameView()
{
  delete window_;
  delete board_;
}

void GameView::openGameView() const
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
    window_->clear(Color(191, 191, 191));
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
  RectangleShape grid = getCell(board_->getActivBlockShapeType());
  int block_position_x = board_->getActiveBlockPositionX();
  int block_position_y = board_->getActiveBlockPositionY();

  board_->doForEachBlockCell([&] (int x, int y) {
    int position_x = grid_offset_x_ + (block_position_x + x) * cell_length_;
    int position_y = grid_offset_y_ + (block_position_y + y) * cell_length_;
    grid.setPosition(position_x, position_y);
    window_->draw(grid);
  });
}

void GameView::drawBackground() const
{
  RectangleShape grid = getCell(Block::EMPTY);
  for (int i = 0; i < Board::board_height_; i++)
  {
    for (int j = 0; j < Board::board_width_; j++)
    {
      int position_x = grid_offset_x_ + j * cell_length_;
      int position_y = grid_offset_y_ + i * cell_length_;
      grid.setPosition(position_x, position_y);
      window_->draw(grid);
    }
  }
}


const sf::RectangleShape GameView::getCell(Block::ShapeType shape_type)
{
  RectangleShape grid(Vector2f(cell_length_, cell_length_));
  switch (shape_type)
  {
    case Block::EMPTY:
      grid.setFillColor(Color(254, 254, 254));
      break;
    case Block::I:
      grid.setFillColor(Color(0, 255, 255));
      break;
    case Block::J:
      grid.setFillColor(Color(0, 0, 255));
      break;
    case Block::L:
      grid.setFillColor(Color(255, 127, 0));
      break;
    case Block::O:
      grid.setFillColor(Color(255, 255, 0));
      break;
  }
  grid.setOutlineColor(Color(193, 193, 193));
  grid.setOutlineThickness(0.6);
  return grid;
}
