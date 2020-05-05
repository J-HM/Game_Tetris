#include "view.h"
#include <iostream>
#include <conio.h>
#include <windows.h>


View::View(std::vector<User> const& user_ranking)
    : user_ranking_(user_ranking)
{
  system("mode con: cols=44 lines=27");
  system("color f1");
}


Menu View::openMenuView() const
{
  char input;
  Menu selected_menu = Start;
  printMenuView(selected_menu);
  while(true)
  {
    if(kbhit())
    {
      input = getch();
      if (input == 13) return selected_menu;
      if (input == 72) selected_menu = Start;
      if (input == 80) selected_menu = End;
      printMenuView(selected_menu);
    }
  }
}

std::string View::openInputNameView() const
{

  char input;
  std::string user_name;
  printNameInputView("");
  while(true)
  {
    if(kbhit())
    {
      input = getch();
      if (input == 13) return user_name;
      if ((input>='a'&& input<='z') || (input>='A' && input<='Z'))
        if (user_name.length() < 15)
          user_name.push_back(input);
      if (input == 8)
        if (user_name.length() > 0)
          user_name.pop_back();
      printNameInputView(user_name);
    }
  }
}

void View::setUserRanking(std::vector<User> const& user_ranking) const
{

}

void View::printHeader() const
{
  std::cout << "############################################";
  std::cout << "#    @@@@@ @@@@@ @@@@@ @@@@   @@@  @@@     #";
  std::cout << "#      @   @       @   @   @   @  @        #";
  std::cout << "#      @   @@@@@   @   @@@@    @   @@@     #";
  std::cout << "#      @   @       @   @   @   @      @    #";
  std::cout << "#      @   @@@@@   @   @   @  @@@  @@@     #";
  std::cout << "#                                          #";
  std::cout << "#                                          #";
  std::cout << "#                                          #";
}

void View::printFooter() const
{
  std::cout << "#                                          #";
  std::cout << "#         *Press ENTER to continue*        #";
  std::cout << "############################################";
}

void View::printUserRanking() const
{
  std::cout << "#                                          #";
  std::cout << "#                                          #";
  std::cout << "#                                          #";
  std::cout << "#                                          #";
  std::cout << "#                                          #";
  for (unsigned int i = 0; i < user_ranking_.size(); i++)
  {
    if (i == 3) break;
    std::string user_name = user_ranking_.at(i).getUserName();
    int user_score = user_ranking_.at(i).getUserScore();
    int user_name_length = user_name.length();
    int user_score_length = 0;
    while (user_score != 0)
    {
      user_score /= 10;
      user_score_length++;
    }
    std::cout << "# ";
    std::cout << i << ". " << user_name << " -> " << user_score;
    for (int i = 0; i < 33 - user_name_length + user_score_length; i++)
      std::cout << " ";
    std::cout << "#";
  }

  for (unsigned int i = 0; i < 3 - user_ranking_.size(); i++)
  {
    std::cout << "#                  te                      #";
  }
}


void View::printNameInputView(std::string user_name) const
{
  system("cls");
  printHeader();
  std::cout << "#             NAME: " << user_name;
  for (unsigned int i = 0; i < 23 - user_name.length(); i++) std:: cout << " ";
  std::cout << "#";
  std::cout << "#                                          #";
  printUserRanking();
  printFooter();
}

void View::printMenuView(Menu selected_menu) const
{
  system("cls");
  printHeader();
  switch(selected_menu)
  {
    case Start:
    {
      std::cout << "#                 > START                  #";
      std::cout << "#                   END                    #";
      break;
    }
    case End:
    {
      std::cout << "#                   START                  #";
      std::cout << "#                 > END                    #";
      break;
    }
  }
  printUserRanking();
  printFooter();
}
