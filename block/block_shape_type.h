#ifndef SHAPE_TYPE_H
#define SHAPE_TYPE_H

class BlockShapeType
{
public:
  BlockShapeType(int shape_type = 0);

  void rotateCw();
  void rotateAcw();
  const int& getIndex() const;
private:
  int shape_type_;
};

#endif
