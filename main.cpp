#include "presenter/lobby_presenter.h"
#include "presenter/presenter.h"

int main()
{
  Presenter* lobby_presenter = new LobbyPresenter();
  lobby_presenter->onCreate();
  return 0;
}
