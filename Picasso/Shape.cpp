#include "Shape.h"
#include <math.h>


Shape::Shape()
{
}

int Shape::dist(Point left,Point right){
	int y = right.y - left.y;
	int x = right.x - left.x;
	y *= y;
	x *= x;
	return round(sqrt((double)x + y));
}
Shape::~Shape()
{
}
