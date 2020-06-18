#include "user.h"

User::User(std::string user_name, int user_score)
    : user_name_(user_name),
      user_score_(user_score)
{
}

std::string User::getUserName() const
{
  return user_name_;
}

int User::getUserScore() const
{
  return user_score_;
}


bool User::operator<(User user) const
{
  if (this->user_score_ == user.user_score_)
  {
    return this->user_name_ < user.user_name_;
  }
  else
  {
    return this->user_score_ < user.user_score_;
  }
}
