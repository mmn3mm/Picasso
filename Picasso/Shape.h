#pragma once
#include <Windows.h>
struct Point{
	int x, y;
};
class Shape
{
public:
	Shape();
	int type; //This will determine the algorithm used to draw.
	COLORREF color;
	~Shape();
};

