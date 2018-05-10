#pragma once
#include "Shape.h"
#include "LineAlgorithm.h"
#include "CircleAlgorithm.h"
#include "CurveAlgorithm.h"
#include "FillAlgorithm.h"
#include <iostream>

class Painter
{
public:
	Painter();
	~Painter();
	void save(HDC hdc);
	void load(HDC hdc);
	void drawLine(HDC,Line);
	void drawCircle(HDC, Circle);
	void drawCurve(HDC, Curve);
	void drawWindow(HDC, int, int, int, int,COLORREF);
	void fill(HDC, Point);
	LineAlgorithm* getLineAlgorithm();
	CircleAlgorithm* getCircleAlgorithm();
	CurveAlgorithm* getCurveAlgorithm();
	FillAlgorithm* getFillAlgorithm();
	vector<Line> lines;
	vector<Circle> circles;
	vector<Curve> curves;
	void clear(HDC hdc);
	vector<Point> fillPoints;
	void setHWND(HWND);
private:
	LineAlgorithm* lineAlgorithm;
	CircleAlgorithm* circleAlgorithm;
	CurveAlgorithm* curveAlgorithm;
	FillAlgorithm* fillAlgorithm;
	HWND hwnd;
};

