#include "Painter.h"


Painter::Painter()
{
	lineAlgorithm = NULL;
}

Painter::~Painter()
{
}

LineAlgorithm* Painter::getLineAlgorithm()
{
	return this->lineAlgorithm;
}
CircleAlgorithm* Painter::getCircleAlgorithm()
{
	return this->circleAlgorithm;
}
void Painter::drawLine(HDC hdc,Line line)
{
	
		lineAlgorithm->draw(hdc,line);
}

void Painter::drawCircle(HDC hdc, Circle circle)
{
	circleAlgorithm->draw(hdc, circle);
}