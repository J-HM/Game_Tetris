#include <iostream>
#include <conio.h>
#include <windows.h>

#include "game_presenter.h"

GamePresenter::GamePresenter()
    : game_view_(new GameView())
{
}


GamePresenter::~GamePresenter()
{
  delete game_view_;
}


void GamePresenter::onCreate()
{
  game_view_->openGameView();

  popPresenter();
}


void GamePresenter::onResume()
{

}

void GamePresenter::onPause()
{
}
