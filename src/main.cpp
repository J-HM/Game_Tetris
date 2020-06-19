#include "game_view/game_view.h"
#include <iostream>

int main()
{
  std::cout << "Test" << std::endl;
  GameView* game_view = new GameView("Hello Tetris!");
  game_view->openView();
  delete game_view;
  return 0;
}


// TODO 1. Reinforce randomness of the waiting block.
// TODO 2. Remove duplicate code in board
// TODO 3. Implement waiting blocks can FIFO
// TODO 4. Implement dropped active blocks changes fragments
// TODO 5. Implement active blocks wall kick when rotating
// TODO 6. Implement line clear checking when active blocks
// changes fragments
// TODO 7. Implement score counting
// TODO 8. Implement delay changing by time
// TODO 9. Refactor Waiting blocks.
// TODO 10. Implement pause / play functions