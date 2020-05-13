#ifndef PRESENTER_H
#define PRESENTER_H


class Presenter
{
public:
  Presenter();
  virtual ~Presenter();

  void pushPresenter(Presenter* next_presenter);
  void popPresenter();

  virtual void onCreate() = 0;
  virtual void onResume() = 0;
  virtual void onPause() = 0;

private:
  Presenter* next_presenter_;
  Presenter* prev_presenter_;
};

#endif
