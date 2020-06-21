#include "game_view.h"

using namespace sf;

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
            board_->rotateAB(Rotation::ACW); // Rotate ACW
            break;
          case Keyboard::C:
            board_->holdAB();      // Hold Block
            break;
          case Keyboard::Space:
            board_->dropABHard();  // Hard Drop
            break;
          case Keyboard::Up:
            board_->rotateAB(Rotation::CW);  // Rotate CW
            break;
          case Keyboard::Right:
            board_->moveAB(Shifting::RIGHT); // Move Right
            break;
          case Keyboard::Down:
            board_->moveAB(Shifting::DOWN);  // Soft Drop
            break;
          case Keyboard::Left:
            board_->moveAB(Shifting::LEFT);  // Move Left
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
      board_->moveAB(Shifting::DOWN);
      tick_timer = 0;
    }

    // Draw precess //
    window_->clear(Color(191, 191, 191));
    drawABZone();
    drawHBZone();
    drawWBZone();
    drawAB();
    drawHB();
    drawWB();

    window_->display();
  }
}


void GameView::drawAB() const
{
  RectangleShape grid = getCell(board_->getABShapeType());
  const Position& block_position = board_->getABPosition();
  board_->loopABCell([&] (int x, int y) {
    int position_x = ab_zone_offset_x_ + (block_position.x_ + x) * cell_length_;
    int position_y = ab_zone_offset_y_ + (block_position.y_ + y) * cell_length_;
    grid.setPosition(position_x, position_y);
    window_->draw(grid);
  });
}

void GameView::drawHB() const
{
  RectangleShape grid = getCell(board_->getHBShapeType());
  board_->loopHBCell([&] (int x, int y) {
    int position_x = hb_zone_offset_x_ + x * cell_length_;
    int position_y = hb_zone_offset_y_ + y * cell_length_;
    grid.setPosition(position_x, position_y);
    window_->draw(grid);
  });
}

void GameView::drawWB() const
{
  for (int i = 0; i < Board::wb_count_; i++)
  {
    RectangleShape grid = getCell(board_->getWBShapeType(i));
    board_->loopWBCell(i, [&] (int x, int y) {
      int position_x = wb_zone_offset_x_ + cell_length_ * x;
      int position_y = wb_zone_offset_y_ + cell_length_ * (y + i * 5);
      grid.setPosition(position_x, position_y);
      window_->draw(grid);
    });
  }
}


void GameView::drawABZone() const
{
  RectangleShape grid = getCell(Block::EMPTY);
  for (int i = 0; i < Board::ab_zone_height_; i++)
  {
    for (int j = 0; j < Board::ab_zone_width_; j++)
    {
      int position_x = ab_zone_offset_x_ + j * cell_length_;
      int position_y = ab_zone_offset_y_ + i * cell_length_;
      grid.setPosition(position_x, position_y);
      window_->draw(grid);
    }
  }
}

void GameView::drawHBZone() const
{
  RectangleShape grid = getCell(Block::EMPTY);
  for (int i = 0; i < Board::hb_zone_height_; i++)
  {
    for (int j = 0; j < Board::hb_zone_width_; j++)
    {
      int position_x = hb_zone_offset_x_ + j * cell_length_;
      int position_y = hb_zone_offset_y_ + i * cell_length_;
      grid.setPosition(position_x, position_y);
      window_->draw(grid);
    }
  }
}

void GameView::drawWBZone() const
{
  RectangleShape grid = getCell(Block::EMPTY);
  for (int i = 1; i < Board::wb_zone_height_; i++)
  {
    for (int j = 0; j < Board::wb_zone_width_; j++)
    {
      int position_x = wb_zone_offset_x_ + j * cell_length_;
      int position_y = wb_zone_offset_y_ + (i - 1) * cell_length_;
      grid.setPosition(position_x, position_y);
      window_->draw(grid);
    }
    if (i % 5 == 4) i += 1;
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
