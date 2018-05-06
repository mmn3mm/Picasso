#pragma once
#include "LineAlgorithm.h"
class SimpleAlgorithm :
	public LineAlgorithm
{
public:
	SimpleAlgorithm();
	~SimpleAlgorithm();
	void draw(HDC,Line);
private:
	void drawLine(HDC hdc, int xs, int ys, int xe, int ye);
};

