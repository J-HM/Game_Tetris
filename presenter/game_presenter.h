#ifndef GAME_PRESENTER_H
#define GAME_PRESENTER_H

#include "presenter.h"

class GamePresenter : public Presenter
{
public:
  GamePresenter();
  ~GamePresenter();

  virtual void onCreate();
  virtual void onResume();
  virtual void onPause();

private:


};

#endif
