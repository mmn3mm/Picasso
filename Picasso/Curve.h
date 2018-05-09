#pragma once
#include "Shape.h"
#include <vector>
class Curve :
	public Shape
{
public:
	Curve();
	std::vector<Point> points;
	~Curve();
};

