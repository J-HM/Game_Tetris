#include "lobby_presenter.h"

#include <algorithm>
#include <iostream>
#include <Windows.h>

#include "game_presenter.h"


LobbyPresenter::LobbyPresenter()
    : lobby_view_(new LobbyView(user_ranking_))
{
}

LobbyPresenter::~LobbyPresenter()
{
  lobby_view_->openEndView();
  delete lobby_view_;
}

void LobbyPresenter::onCreate()
{
  presentMenuView();
}

void LobbyPresenter::onResume()
{
  presentMenuView();
}

void LobbyPresenter::presentMenuView()
{
  while(true)
  {
    Menu selected_menu = lobby_view_->openMenuView();
    if (selected_menu == Start)
    {
      std::string user_name = lobby_view_->openInputNameView();
      Presenter* game_presenter = new GamePresenter;
      pushPresenter(game_presenter);
    }
    else if (selected_menu == End)
    {
      popPresenter();
    }
  }
}

void LobbyPresenter::onPause()
{
}
