#include <iostream>
#include <Windows.h>

#include "presenter.h"


Presenter::Presenter(std::string test_class_name)
    : test_class_name(test_class_name)
{
  std::cout << test_class_name << " 의 부모 생성자 호출" << std::endl;
  Sleep(2000);
  next_presenter_ = nullptr;
  prev_presenter_ = nullptr;
}

Presenter::~Presenter()
{
  std::cout << test_class_name << " 의 부모 소멸자 호출" << std::endl;
  Sleep(2000);

  if (prev_presenter_ == nullptr)
  {
    std::cout << test_class_name << " 의 마지막 부모 소멸자 호출" << std::endl;
    Sleep(2000);
    delete next_presenter_;
    delete prev_presenter_;
  }
}

void Presenter::pushPresenter(Presenter* next_presenter)
{
  std::cout << this->test_class_name << " 가 Push를 호출" << std::endl;
  std::cout << next_presenter->test_class_name << " 가 Stack 의 Top 으로 Push" << std::endl;
  Sleep(2000);

  next_presenter->prev_presenter_ = this;
  this->next_presenter_ = next_presenter;

  this->onPause();
  next_presenter->onCreate();
}

void Presenter::popPresenter()
{
  if (this->prev_presenter_ != nullptr)
  {
    std::cout << this->test_class_name << " 가 PoP을 호출" << std::endl;
    std::cout << this->test_class_name << " 가 Stack 의 Top 에서 Pop" << std::endl;
    Sleep(2000);

    Presenter* prev_presenter = this->prev_presenter_;

    this->prev_presenter_->next_presenter_ = nullptr;
    this->onDestroy();
    delete this;

    prev_presenter->onResume();
  }
  else
  {
    std::cout << this->test_class_name << " 가 PoP을 호출!" << std::endl;
    std::cout << "더이상 Stack에 존재하는 프리센터가 없음!" << std::endl;
    Sleep(2000);

    this->onDestroy();
    delete this;
  }
}
