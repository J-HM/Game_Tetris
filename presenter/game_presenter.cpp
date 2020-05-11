#include <iostream>
#include <Windows.h>
#include <conio.h>

#include "game_presenter.h"

GamePresenter::GamePresenter()
    : Presenter("������������!")
{
  std::cout << "�����������Ϳ��� ������ ȣ��" << std::endl;
  Sleep(2000);
}


GamePresenter::~GamePresenter()
{
  std::cout << "�����������Ϳ��� �Ҹ��� ȣ��" << std::endl;
  Sleep(2000);
}


void GamePresenter::onCreate()
{
  std::cout << "�����������Ϳ��� onCreate() ȣ��" << std::endl;
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
  std::cout << "�����������Ϳ��� onResume() ȣ��" << std::endl;
  Sleep(2000);
}

void GamePresenter::onPause()
{
  std::cout << "�����������Ϳ��� onPause() ȣ��" << std::endl;
  Sleep(2000);

}

void GamePresenter::onDestroy()
{
  std::cout << "�����������Ϳ��� onDestroy() ȣ��" << std::endl;
  Sleep(2000);
}
