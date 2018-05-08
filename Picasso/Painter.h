#pragma once
#include "Shape.h"
#include "LineAlgorithm.h"
#include "CircleAlgorithm.h"
class Painter
{
public:
	Painter();
	~Painter();
	enum LineAlgorithmType
	{
		Simple, DDA, MidPoint
	};
	void drawLine(HDC,Line);
	void drawCircle(HDC, Circle);
	LineAlgorithm* getLineAlgorithm();
	CircleAlgorithm* getCircleAlgorithm();
private:
	LineAlgorithm* lineAlgorithm;
	CircleAlgorithm* circleAlgorithm;

};

