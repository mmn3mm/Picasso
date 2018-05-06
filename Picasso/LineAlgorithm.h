#pragma once
#include "Line.h"
#include <math.h>
#include "windows.h"
#include <algorithm>
class LineAlgorithm
{
public:
	LineAlgorithm();
	~LineAlgorithm();
	virtual void draw(HDC,Line) = 0;
};

