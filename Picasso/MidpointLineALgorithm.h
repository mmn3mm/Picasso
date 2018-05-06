#pragma once
#include "LineAlgorithm.h"
class MidpointLineALgorithm :
	public LineAlgorithm
{
public:
	MidpointLineALgorithm();
	~MidpointLineALgorithm();
	void drawLineMidPoint(HDC hdc, Line line, COLORREF);
	void draw(HDC,Line);
};

