#include <SFML/Graphics.hpp>

#include "game_view.h"


using namespace sf;

GameView::GameView()
{
}

void GameView::openGameView() const
{
  RenderWindow window(VideoMode(300, 500), "Hello Tetris");

  Text text;
  text.setString("Hello Tetris");
  text.setCharacterSize(24);
  text.setFillColor(Color::Black);
  text.setStyle(sf::Text::Bold | sf::Text::Underlined);

  RectangleShape rectangle(Vector2f(120, 50));
  rectangle.setFillColor(Color(100, 250, 50));

  while (window.isOpen())
  {
    Event event;
    while (window.pollEvent(event))
    {
      if (event.type == Event::Closed)
        {
          window.close();
        }
    }


    window.clear(Color::White);
    window.draw(rectangle);
    window.display();
  }
}
