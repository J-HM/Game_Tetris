#ifndef PRESENTER_H
#define PRESENTER_H

#include <string>

class Presenter
{
public:
  Presenter(std::string test_class_name);
  virtual ~Presenter();

  void pushPresenter(Presenter* next_presenter);
  void popPresenter();

  virtual void onCreate() = 0;
  virtual void onResume() = 0;
  virtual void onPause() = 0;
  virtual void onDestroy() = 0;

  std::string test_class_name;
private:
  Presenter* next_presenter_;
  Presenter* prev_presenter_;
};

#endif
