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

void GameView::openView() const
{
  sf::Clock clock;
  bool is_paused = false;
  float game_delay = 0.5;
  float tick_timer = 0;

  while (window_->isOpen())
  {
    tick_timer += clock.getElapsedTime().asSeconds();
    clock.restart();

    // event process //
    Event event;
    while (window_->pollEvent(event))
    {
      if (event.type == Event::Closed)
      {
        window_->close();
      }
      if (event.type == Event::KeyPressed)
      {
        switch (event.key.code)
        {
          case Keyboard::Escape:
            is_paused = !is_paused;         // Pause / Play
            break;
          case Keyboard::Z:
            board_->rotateABlock(Rotation::ACW); // Rotate ACW
            break;
          case Keyboard::C:
            board_->holdABlock();      // Hold Block
            break;
          case Keyboard::Space:
            board_->dropABlockHard();  // Hard Drop
            break;
          case Keyboard::Up:
            board_->rotateABlock(Rotation::CW);  // Rotate CW
            break;
          case Keyboard::Right:
            board_->moveABlock(Shifting::RIGHT); // Move Right
            break;
          case Keyboard::Down:
            board_->moveABlock(Shifting::DOWN);  // Soft Drop
            break;
          case Keyboard::Left:
            board_->moveABlock(Shifting::LEFT);  // Move Left
            break;
          default:
            std::cout << "Warning: Different Key is pressed." << std::endl;
        }
      }
    }

    // Pause / Play //
    if (is_paused) continue;

    // Tick //
    if (tick_timer > game_delay)
    {
      const bool isDropping = board_->dropABlock();

      if (isDropping)
      {
        std::cout << "block is floating in the air" << std::endl;
      }
      else // ABlock is on fragments or bottom wall
      {
        std::cout << "block is on fragments or bottom wall" << std::endl;
      }
      tick_timer = 0;
    }


    // Draw precess //
    window_->clear(Color(191, 191, 191));
    drawBackground();
    drawBench();
    drawWaitingBlock();


    drawActiveBlock();

    window_->display();
  }
}

void GameView::drawActiveBlock() const
{
  RectangleShape grid = getCell(board_->getABlockShapeType());
  const Position& block_position = board_->getABlockPosition();

  board_->loopABlockCell([&] (int x, int y) {
    int position_x = board_offset_x_ + (block_position.x_ + x) * cell_length_;
    int position_y = board_offset_y_ + (block_position.y_ + y) * cell_length_;
    grid.setPosition(position_x, position_y);
    window_->draw(grid);
  });
}

void GameView::drawBench() const
{
  RectangleShape grid = getCell(Block::EMPTY);
  for (int i = 1; i < 15; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      int position_x = bench_offset_x_ + j * cell_length_;
      int position_y = bench_offset_y_ + (i - 1) * cell_length_;
      grid.setPosition(position_x, position_y);
      window_->draw(grid);
    }
    if (i % 5 == 4) i += 1;
  }

}

void GameView::drawWaitingBlock() const
{

}

void GameView::drawBackground() const
{
  RectangleShape grid = getCell(Block::EMPTY);
  for (int i = 0; i < Board::board_height_; i++)
  {
    for (int j = 0; j < Board::board_width_; j++)
    {
      int position_x = board_offset_x_ + j * cell_length_;
      int position_y = board_offset_y_ + i * cell_length_;
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
