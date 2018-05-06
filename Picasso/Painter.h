#pragma once
#include "Shape.h"
#include "LineAlgorithm.h"
#include "SimpleAlgorithm.h"
#include "SimpleAlgorithmDDA.h"
#include "MidpointLineALgorithm.h"
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
	void setLineAlgorithm(int);
	LineAlgorithm* getLineAlgorithm();
private:
	LineAlgorithm* lineAlgorithm;

};

