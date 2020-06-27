#include "game_view.hpp"


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
  bool is_z_pressed = false;  // Protect z continuous input
  bool is_up_pressed = false; // Protect up continuous input
  bool is_paused = false;
  sf::Clock tick_clock;
  double tick_delay = 1.0 / 1.0;
  double lock_delay = 0.8;
  double tick_timer = 0;
  while (window_->isOpen())
  {
    tick_timer += tick_clock.getElapsedTime().asSeconds();
    tick_clock.restart();
    // event process //
    Event event;
    while (window_->pollEvent(event))
    {
      if (event.type == Event::Closed)
      {
        window_->close();
      }
      else if (event.type == Event::KeyPressed)
      {
        if (event.key.code == Keyboard::Escape)
          is_paused = !is_paused;          // Pause / Play
        else if (event.key.code == Keyboard::Z && !is_z_pressed)
        {
          is_z_pressed = true;
          board_->rotateAB(Rotation::ACW); // Rotate ACW
        }  
        else if (event.key.code == Keyboard::C)
          board_->swapABwithHB();                // Hold Block
        else if (event.key.code == Keyboard::Space)
          board_->dropABHard();            // Hard Drop
        else if (event.key.code == Keyboard::Up && !is_up_pressed)
        {
          is_up_pressed = true;
          board_->rotateAB(Rotation::CW);  // Rotate CW
        }
        else if (event.key.code == Keyboard::Right)
          board_->moveAB(Shifting::RIGHT); // Move Right
        else if (event.key.code == Keyboard::Down)
          board_->moveAB(Shifting::DOWN);  // Soft Drop
        else if (event.key.code == Keyboard::Left)
          board_->moveAB(Shifting::LEFT);  // Move Left
        else
          std::cout << "Warning: Different Key is pressed." << std::endl;
      }
      else if (event.type == Event::KeyReleased)
      {
        if (event.key.code == Keyboard::Z)
          is_z_pressed = false;
        if (event.key.code == Keyboard::Up)
          is_up_pressed = false;
      }
    }

    // Pause / Play //
    if (is_paused) continue;

    // Tick //
    if (tick_timer > tick_delay && board_->getIsABFalling())
    {
      board_->moveAB(Shifting::DOWN);
      tick_timer = 0;
    }

    if (tick_timer > lock_delay && !board_->getIsABFalling())
    {
      std::cout << "Time to stop!" << std::endl;
      board_->pushABtoFrags();
      board_->checkFrags();
      board_->popWBToAB();
      tick_timer = 0;
    }

    // Draw precess //
    window_->clear(Color(233, 255, 233));
    drawABZone();
    drawHBZone();
    drawWBZone();
    drawAB();
    drawHB();
    drawWBs();
    drawFrags();
    window_->display();
  }
}


void GameView::drawAB() const
{
  RectangleShape cell = getCell(board_->getABShapeType());
  const Position& block_position = board_->getABPosition();
  board_->loopABCells([&cell, &block_position, &window = window_] (int x, int y)
  {
    int position_x = ab_zone_offset_x_ + (block_position.x_ + x) * cell_length_;
    int position_y = ab_zone_offset_y_ + (block_position.y_ + y) * cell_length_;
    cell.setPosition(position_x, position_y);
    window->draw(cell);
    return false; // Will not End
  });
}

void GameView::drawHB() const
{
  RectangleShape cell = getCell(board_->getHBShapeType());
  board_->loopHBCells([&cell, &window = window_] (int x, int y)
  {
    int position_x = hb_zone_offset_x_ + x * cell_length_;
    int position_y = hb_zone_offset_y_ + y * cell_length_;
    cell.setPosition(position_x, position_y);
    window->draw(cell);
    return false; // To not break loop
  });
}

void GameView::drawWBs() const
{
  for (int i = 0; i < Board::wb_count_; i++)
  {
    RectangleShape cell = getCell(board_->getWBhapeType(i));
    board_->loopWBCells(i, [i, &cell, &window = window_] (int x, int y)
    {
      int position_x = wb_zone_offset_x_ + cell_length_ * x;
      int position_y = wb_zone_offset_y_ + cell_length_ * (y + i * 5);
      cell.setPosition(position_x, position_y);
      window->draw(cell);
      return false; // To not break loop
    });
  }
}


void GameView::drawABZone() const
{
  RectangleShape cell = getCell(Block::EMPTY);
  for (int i = 0; i < Board::ab_zone_height_; i++)
  {
    for (int j = 0; j < Board::ab_zone_width_; j++)
    {
      int position_x = ab_zone_offset_x_ + j * cell_length_;
      int position_y = ab_zone_offset_y_ + i * cell_length_;
      cell.setPosition(position_x, position_y);
      window_->draw(cell);
    }
  }
}

void GameView::drawHBZone() const
{
  RectangleShape cell = getCell(Block::EMPTY);
  for (int i = 0; i < Board::hb_zone_height_; i++)
  {
    for (int j = 0; j < Board::hb_zone_width_; j++)
    {
      int position_x = hb_zone_offset_x_ + j * cell_length_;
      int position_y = hb_zone_offset_y_ + i * cell_length_;
      cell.setPosition(position_x, position_y);
      window_->draw(cell);
    }
  }
}

void GameView::drawWBZone() const
{
  RectangleShape cell = getCell(Block::EMPTY);
  for (int i = 1; i < Board::wb_zone_height_; i++)
  {
    for (int j = 0; j < Board::wb_zone_width_; j++)
    {
      int position_x = wb_zone_offset_x_ + j * cell_length_;
      int position_y = wb_zone_offset_y_ + (i - 1) * cell_length_;
      cell.setPosition(position_x, position_y);
      window_->draw(cell);
    }
    if (i % 5 == 4) i += 1;
  }
}


void GameView::drawFrags() const
{
  board_->loopFrags([&window = window_] (Fragment& fragment, Block::ShapeType shape_type) 
    {
      RectangleShape cell = getCell(shape_type);
      int position_x = ab_zone_offset_x_ + fragment.getPosition().x_ * cell_length_;
      int position_y = ab_zone_offset_y_ + fragment.getPosition().y_ * cell_length_;
      cell.setPosition(position_x, position_y);
      window->draw(cell);
      return false; // To not break loop
    }
  );
}


const sf::RectangleShape GameView::getCell(Block::ShapeType shape_type)
{
  RectangleShape cell(Vector2f(cell_length_ - 2, cell_length_ - 2));
  switch (shape_type)
  {
    case Block::EMPTY:
      cell.setFillColor(Color(55, 55, 55));
      break;
    case Block::I:
      cell.setFillColor(Color(0, 255, 255));
      break;
    case Block::J:
      cell.setFillColor(Color(0, 0, 255));
      break;
    case Block::L:
      cell.setFillColor(Color(255, 127, 0));
      break;
    case Block::O:
      cell.setFillColor(Color(255, 255, 0));
      break;
    case Block::S:
      cell.setFillColor(Color(0, 255, 0));
      break;
    case Block::T:
      cell.setFillColor(Color(127, 0, 255));
      break;
    case Block::Z:
      cell.setFillColor(Color(255, 0, 0));
      break;
  }
  cell.setOutlineColor(Color(33, 33, 33));
  cell.setOutlineThickness(1);
  return cell;
}