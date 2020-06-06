#ifndef SHAPE_TYPE_H
#define SHAPE_TYPE_H


class ShapeType
{
public:
  ShapeType(short int shape_type = 0);

  void rotateCw();
  void rotateAcw();
  const short int& getIndex() const;

private:
  short int shape_type_;
};

#endif
