#ifndef GAME_HANDLER_H
#define GAME_HANDLER_H

#include <string>
#include <vector>
#include "../view/view.h"
#include "../user/user.h"

class GameHandler
{
public:
  GameHandler();
  ~GameHandler();

private:
  void handleChoice();
  int startGame();
  void endGame();

private:
  View* view_;
  std::string user_name_;
  std::vector<User> user_ranking_;
};

#endif
