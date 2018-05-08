#pragma once
#include "Shape.h"
class Circle :
	public Shape
{
public:
	Point center;
	Point radius;
	Circle();
	Circle(Point, Point);
	~Circle();
};

