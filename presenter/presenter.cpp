#include "presenter.h"


Presenter::Presenter()
    : next_presenter_(nullptr),
      prev_presenter_(nullptr)
{
}

Presenter::~Presenter()
{
}

void Presenter::pushPresenter(Presenter* next_presenter)
{
  this->next_presenter_ = next_presenter;
  next_presenter->prev_presenter_ = this;

  this->onPause();
  next_presenter->onCreate();
}

void Presenter::popPresenter()
{
  // If this presenter is not root presenter
  if (this->prev_presenter_ != nullptr)
  {
    Presenter* prev_presenter = this->prev_presenter_;
    this->prev_presenter_->next_presenter_ = nullptr;
    delete this;
    prev_presenter->onResume();
  }
  // If this presenter is not root presenter
  else
  {
    delete this;
  }
}
