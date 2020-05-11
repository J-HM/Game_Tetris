#include <iostream>
#include <Windows.h>
#include <conio.h>

#include "game_presenter.h"

GamePresenter::GamePresenter()
    : Presenter("게임프리젠터!")
{
  std::cout << "게임프리젠터에서 생성자 호출" << std::endl;
  Sleep(2000);
}


GamePresenter::~GamePresenter()
{
  std::cout << "게임프리젠터에서 소멸자 호출" << std::endl;
  Sleep(2000);
}


void GamePresenter::onCreate()
{
  std::cout << "게임프리젠터에서 onCreate() 호출" << std::endl;
  Sleep(2000);

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
  std::cout << "게임프리젠터에서 onResume() 호출" << std::endl;
  Sleep(2000);
}

void GamePresenter::onPause()
{
  std::cout << "게임프리젠터에서 onPause() 호출" << std::endl;
  Sleep(2000);

}

void GamePresenter::onDestroy()
{
  std::cout << "게임프리젠터에서 onDestroy() 호출" << std::endl;
  Sleep(2000);
}
