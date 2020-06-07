#include "view/game_view.h"

int main()
{
  GameView* game_view = new GameView("Hello Tetris!");
  game_view->openGameView();
  delete game_view;
  return 0;
}
