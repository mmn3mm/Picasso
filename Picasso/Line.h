#pragma once
#include "Shape.h"

class Line :
	public Shape
{
public:
	Line();
	~Line();
	Point start;
	Point end;
	//LineAlgorithm 
};

