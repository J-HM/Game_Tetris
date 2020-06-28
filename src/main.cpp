#include "game_view/game_view.hpp"


int main()
{
  GameView* game_view = new GameView("Hello Tetris!");
  game_view->openView();
  delete game_view;
  return 0;
}

// TODO 1. Reinforce randomness of the waiting block.
// TODO 2. Implement active blocks wall kick when rotating
// TODO 3. Implement score counting
// TODO 4. Implement delay changing by time
// TODO 5. Implement pause / play functions
// TODO 6. Implement fragment check when moving