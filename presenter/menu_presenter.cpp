#include <algorithm>
#include <iostream>
#include <Windows.h>

#include "../presenter/menu_presenter.h"
#include "game_presenter.h"


MenuPresenter::MenuPresenter()
    : Presenter("메뉴프리젠터!"),
      view_(new MenuView(user_ranking_))
{
  std::cout << "메뉴프리젠터에서 생성자 호출" << std::endl;
  Sleep(2000);
}

MenuPresenter::~MenuPresenter()
{
  std::cout << "메뉴프리젠터에서 소멸자 호출" << std::endl;
  Sleep(2000);
}

void MenuPresenter::onCreate()
{
  std::cout << "메뉴프리젠터에서 onCreate() 호출" << std::endl;
  Sleep(2000);
  presentMenuView();
}

void MenuPresenter::onResume()
{
  std::cout << "메뉴프리젠터에서 onResume() 호출" << std::endl;
  Sleep(2000);
  presentMenuView();
}

void MenuPresenter::presentMenuView()
{
  while(true)
  {
    Menu selected_menu = view_->openMenuView();
    if (selected_menu == Start)
    {
      std::string user_name = view_->openInputNameView();
      Presenter* game_presenter = new GamePresenter;
      pushPresenter(game_presenter);
    }
    else if (selected_menu == End)
    {
      popPresenter();
    }
  }
}

void MenuPresenter::onPause()
{
  std::cout << "메뉴프리젠터에서 onPause() 호출" << std::endl;
  Sleep(2000);
}

void MenuPresenter::onDestroy()
{
  std::cout << "메뉴프리젠터에서 onDestroy() 호출" << std::endl;
  Sleep(2000);
  delete view_;
}
