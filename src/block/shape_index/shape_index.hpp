#ifndef SHAPE_TYPE_HPP
#define SHAPE_TYPE_HPP


class ShapeIndex
{
public:
  ShapeIndex(int shape_type = 0);

  void rotateCw();
  void rotateAcw();
  const int& getIndex() const;

private:
  int shape_index_;
};

#endif
