#include "presenter/presenter.h"
#include "presenter/menu_presenter.h"

int main()
{
  Presenter* menu_presenter = new MenuPresenter();
  menu_presenter->onCreate();
  delete menu_presenter;
  return 0;
}
