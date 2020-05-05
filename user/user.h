#ifndef USER_H
#define USER_H

#include <string>

class User
{
public:
  User(std::string user_name, int user_score);
  bool operator<(User user) const;

  std::string getUserName() const;
  int getUserScore() const;

private:
  std::string user_name_;
  int user_score_;
};

#endif
