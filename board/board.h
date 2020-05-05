#ifndef BOARD_H
#define BOARD_H

#include <vector>

class Board
{
public:
  static const int k_board_width;
  static const int k_board_height;

public:
  Board();
  void printBoard() const;

private:
  std::vector<std::vector<bool>> board;

};

#endif
