#ifndef SHAPE_TYPE_H
#define SHAPE_TYPE_H

class ShapeType
{
public:
  ShapeType(int shape_type = 0);

  void rotateCw();
  void rotateAcw();
  const int& getIndex() const;
private:
  int shape_type_;
};

#endif
