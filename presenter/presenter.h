#ifndef PRESENTER_H
#define PRESENTER_H


class Presenter
{
public:
  Presenter();
  void pushPresenter(Presenter* presenter);
  void popPresenter();

private:
  Presenter* nextPresenter_;
  Presenter* prevPresenter_;
};

#endif
