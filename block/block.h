#ifndef BLOCK_H
#define BLOCK_H

#include "../point/point.h"

class Block
{
public:
	Block(Point _shape[4], Point _axis) {
		shape[0] = _shape[0];
		shape[1] = _shape[1];
		shape[2] = _shape[2];
		shape[3] = _shape[3];
	}

	void turnLeft();
	void turnRight();
	void dropDown();

	void setShape();
	Point getShape();

private:
	Point shape[4];
	const Point axis;
};

#endif
