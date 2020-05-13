#ifndef LOBBY_PRESENTER_H
#define LOBBY_PRESENTER_H

#include <string>
#include <vector>
#include "presenter.h"
#include "../model/user/user.h"
#include "../view/lobby_view.h"

class LobbyPresenter : public Presenter
{
public:
  LobbyPresenter();
  ~LobbyPresenter();

  virtual void onCreate();
  virtual void onResume();
  virtual void onPause();

private:
  void presentMenuView();

private:
  LobbyView* lobby_view_;
  std::vector<User> user_ranking_;
};

#endif
