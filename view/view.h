#ifndef VIEW_H
#define VIEW_H

#include <string>
#include <vector>
#include "../user/user.h"

enum Menu { Start, End };

class View
{
public:
  View(std::vector<User> const& user_ranking);
  Menu openMenuView() const;
  std::string openInputNameView() const;
  void setUserRanking(std::vector<User> const& user_ranking) const;

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
