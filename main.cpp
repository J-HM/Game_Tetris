#include "presenter/presenter.h"
#include "presenter/menu_presenter.h"

int main()
{
  Presenter* menu_presenter = new MenuPresenter();
  delete menu_presenter;
  return 0;
}
