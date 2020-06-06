#include "view/game_view.h"

int main()
{
  GameView* game_view = new GameView();
  game_view->openGameView("Hello Tetris!");
  delete game_view;
  return 0;
}
