#include <iostream>
#include <Windows.h>
#include <conio.h>

#include "game_presenter.h"
GamePresenter::GamePresenter()
{
  char input;
  while(true)
  {
    if(kbhit())
    {
      input = getch();
      if (input == 13) {
        popPresenter();
        break;
      }
      if (input == 72) std::cout << "wow";
      if (input == 80) std::cout << "Good";
    }
  }

}
