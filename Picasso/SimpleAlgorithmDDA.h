#pragma once
#include "LineAlgorithm.h"
class SimpleAlgorithmDDA :
	public LineAlgorithm
{
public:
	SimpleAlgorithmDDA();
	~SimpleAlgorithmDDA();
	void draw(HDC,Line);
private:
	void drawLine(HDC hdc, int xs, int ys, int xe, int ye);
};

