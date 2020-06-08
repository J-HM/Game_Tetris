#ifndef SHAPE_TYPE_H
#define SHAPE_TYPE_H


class ShapeIndex
{
public:
  ShapeIndex(short int shape_type = 0);

  void rotateCw();
  void rotateAcw();
  const short int& getIndex() const;

private:
  short int shape_index_;
};

#endif
