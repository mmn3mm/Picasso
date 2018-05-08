#pragma once
#include "Line.h"
#include <math.h>
#include "windows.h"
#include <algorithm>
class LineAlgorithm
{
public:
	enum LineAlgorithmType
	{
		Simple, DDA, MidPoint
	};
	LineAlgorithm();
	~LineAlgorithm();
	void draw(HDC, Line);
	int  type;
	void drawSimple(HDC, Line);
	void drawMidPoint(HDC, Line);
	void drawDDA(HDC, Line);
};

