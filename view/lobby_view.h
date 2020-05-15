#ifndef MENU_VIEW_H
#define MENU_VIEW_H

#include <string>
#include <vector>

#include "../model/user/user.h"
#include "../model/board/board.h"


enum Menu { Start, End };

class LobbyView
{
public:
  LobbyView(std::vector<User> const& user_ranking);

  Menu openMenuView() const;
  void openEndView() const;
  std::string openInputNameView() const;

private:
  void printHeader() const;
  void printFooter() const;
  void printUserRanking() const;
  void printMenuView(Menu selected_menu) const;
  void printNameInputView(std::string user_name) const;

private:
  std::vector<User> const& user_ranking_;
};


#endif
