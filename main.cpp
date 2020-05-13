#include "presenter/lobby_presenter.h"
#include "presenter/presenter.h"

int main()
{
  Presenter* menu_presenter = new LobbyPresenter();
  menu_presenter->onCreate();
  return 0;
}
