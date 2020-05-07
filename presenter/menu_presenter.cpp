#include <algorithm>
#include <iostream>
#include <Windows.h>

#include "../presenter/menu_presenter.h"
#include "game_presenter.h"


MenuPresenter::MenuPresenter()
    : view_(new MenuView(user_ranking_))
{
  presentMenuView();
}

MenuPresenter::~MenuPresenter()
{
  delete view_;
  system("cls");
  std::cout << "Menu Presenter Deleted." << std::endl;
  Sleep(1000);
}

void MenuPresenter::presentMenuView()
{
  while(true)
  {
    Menu selected_menu = view_->openMenuView();
    if (selected_menu == Start)
    {
      std::string user_name = view_->openInputNameView();
      pushPresenter(new GamePresenter);
//      user_ranking_.push_back(User(user_name, user_score));
//      sort(user_ranking_.begin(), user_ranking_.end());
    }
    else if (selected_menu == End)
    {
      popPresenter();
      break;
    }
  }
}
