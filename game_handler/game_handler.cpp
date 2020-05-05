#include "game_handler.h"

#include <algorithm>

GameHandler::GameHandler()
    : view_(new View(user_ranking_))
{
  handleChoice();
}

GameHandler::~GameHandler()
{
  delete view_;
}


void GameHandler::handleChoice()
{
  while(true)
  {
    Menu selected_menu = view_->openMenuView();
    if (selected_menu == Start)
    {
      std::string user_name = view_->openInputNameView();
      int user_score = startGame();
      user_ranking_.push_back(User(user_name, user_score));
      sort(user_ranking_.begin(), user_ranking_.end());
    }
    else if (selected_menu == End)
    {
      endGame();
      break;
    }
  }
}

int GameHandler::startGame()
{
  return 0;
}

void GameHandler::endGame()
{
  // Empty
}
