#include <algorithm>
#include <iostream>
#include <Windows.h>

#include "../presenter/menu_presenter.h"
#include "game_presenter.h"


MenuPresenter::MenuPresenter()
    : Presenter("�޴���������!"),
      view_(new MenuView(user_ranking_))
{
  std::cout << "�޴��������Ϳ��� ������ ȣ��" << std::endl;
  Sleep(2000);
}

MenuPresenter::~MenuPresenter()
{
  std::cout << "�޴��������Ϳ��� �Ҹ��� ȣ��" << std::endl;
  Sleep(2000);
}

void MenuPresenter::onCreate()
{
  std::cout << "�޴��������Ϳ��� onCreate() ȣ��" << std::endl;
  Sleep(2000);
  presentMenuView();
}

void MenuPresenter::onResume()
{
  std::cout << "�޴��������Ϳ��� onResume() ȣ��" << std::endl;
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
  std::cout << "�޴��������Ϳ��� onPause() ȣ��" << std::endl;
  Sleep(2000);
}

void MenuPresenter::onDestroy()
{
  std::cout << "�޴��������Ϳ��� onDestroy() ȣ��" << std::endl;
  Sleep(2000);
  delete view_;
}
