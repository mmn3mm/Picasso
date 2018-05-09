#pragma once
#include "Shape.h"
#include "LineAlgorithm.h"
#include "CircleAlgorithm.h"
#include "CurveAlgorithm.h"

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
	void drawCurve(HDC, Curve);
	void drawWindow(HDC, int, int, int, int,COLORREF);
	LineAlgorithm* getLineAlgorithm();
	CircleAlgorithm* getCircleAlgorithm();
	CurveAlgorithm* getCurveAlgorithm();
private:
	LineAlgorithm* lineAlgorithm;
	CircleAlgorithm* circleAlgorithm;
	CurveAlgorithm* curveAlgorithm;
};

