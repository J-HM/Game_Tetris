#ifndef POINT_H
#define POINT_H

class Point
{
 public:
  Point();
  Point(int _x, int _y);

  Point& operator=(Point& _point);
  Point& operator--();

  int getX();
  int getY();

 private:
  int x = 0;
  int y = 0;
};

#endif
