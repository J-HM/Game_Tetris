#ifndef GAME_PRESENTER_H
#define GAME_PRESENTER_H

#include "presenter.h"
#include "../view/game_view.h"

class GamePresenter : public Presenter
{
public:
  GamePresenter();
  ~GamePresenter();

  virtual void onCreate();
  virtual void onResume();
  virtual void onPause();

private:
  GameView* game_view_;

};

#endif
