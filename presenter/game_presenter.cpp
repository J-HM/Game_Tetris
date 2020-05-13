#include <iostream>
#include <conio.h>

#include "game_presenter.h"

GamePresenter::GamePresenter()
{

}


GamePresenter::~GamePresenter()
{

}


void GamePresenter::onCreate()
{


  char input;
  while(true)
  {
    if(kbhit())
    {
      input = getch();
      if (input == 13)
      {
        popPresenter();
      }
      if (input == 72) std::cout << "wow";
      if (input == 80) std::cout << "Good";
    }
  }
}


void GamePresenter::onResume()
{

}

void GamePresenter::onPause()
{
}
