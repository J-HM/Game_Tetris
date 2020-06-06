#include "game_view.h"


using namespace sf;
using std::array;

GameView::GameView()
    : board_(new Board()),
      is_paused_(false)
{
}

GameView::~GameView()
{
  delete board_;
}

void GameView::openGameView(std::string title)
{
  sf::RenderWindow window(VideoMode(500, 500), title, Style::Close);



  while (window.isOpen())
  {
    // event process //
    Event event;
    while (window.pollEvent(event))
    {
      if (event.type == Event::Closed)
        window.close();
      if (event.type == Event::KeyPressed)
      {
        if (event.key.code == Keyboard::Escape)
          is_paused_ = !is_paused_; // Pause / Play
        else if (event.key.code == Keyboard::Z)
          board_->rotateBlockAcw(); // Rotate ACW
        else if (event.key.code == Keyboard::C)
          board_->holdBlock();      // Hold Block
        else if (event.key.code == Keyboard::Space)
          board_->dropBlockHard();  // Hard Drop
        else if (event.key.code == Keyboard::Up)
          board_->rotateBlockCw();  // Rotate CW
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
    window.clear(Color(221, 221, 221));
    drawDefaultBackground(window);

    if (is_paused_)
    {
      continue;
    }

    board_->drawActiveBlock([&window] (int x, int y) {
      RectangleShape grid(Vector2f(grid_length, grid_length));
      grid.setFillColor(Color(108, 18, 248));
      grid.setOutlineColor(Color(153, 153, 153));
      grid.setOutlineThickness(1.0);
      int position_x = grids_offset_x + x * grid_length;
      int position_y = grids_offset_y + y * grid_length;
      grid.setPosition(position_x, position_y);
      window.draw(grid);
    });

    window.display();
  }
}

void GameView::drawDefaultBackground(sf::RenderWindow& window) const
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
      window.draw(grid);
    }
  }
}
