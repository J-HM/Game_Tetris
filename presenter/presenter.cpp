#include <iostream>
#include <Windows.h>

#include "presenter.h"


Presenter::Presenter()
{
  nextPresenter_ = NULL;
  prevPresenter_ = NULL;
}

void Presenter::pushPresenter(Presenter* presenter)
{
  presenter->prevPresenter_ = this;
  this->nextPresenter_ = presenter;
}

void Presenter::popPresenter()
{
  if (!prevPresenter_)
  {
    system("cls");
    std::cout << "Pop current Presenter" << std::endl;
    Sleep(5000);
    delete prevPresenter_->nextPresenter_;
  }
  else
  {
    system("cls");
    std::cout << "It is Last Presenter." << std::endl;
    std::cout << "Program will terminate." << std::endl;
    Sleep(5000);
  }
}
