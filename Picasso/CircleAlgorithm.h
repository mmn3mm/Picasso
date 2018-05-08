#pragma once
#include "Circle.h"
class CircleAlgorithm
{
private:
public:
	
	CircleAlgorithm();
	enum CircleAlgorithmType{
		Simple,
		Polar,
		MidPoint
	};
	void draw(HDC, Circle);
	void draw8Points(HDC hdc, int xc, int yc, int x, int y, COLORREF color);
	void drawCircleMidPoint(HDC, Circle);
	void drawCircleQuadratic(HDC, Circle);
	void drawPolar(HDC, Circle);
	~CircleAlgorithm();
};

