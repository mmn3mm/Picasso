#include "Painter.h"


Painter::Painter()
{
	curveAlgorithm = new CurveAlgorithm();
	lineAlgorithm = new LineAlgorithm();
	circleAlgorithm = new CircleAlgorithm();
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
CurveAlgorithm* Painter::getCurveAlgorithm()
{
	return this->curveAlgorithm;
}
void Painter::drawLine(HDC hdc,Line line)
{
	
	lineAlgorithm->draw(hdc,line);
}

void Painter::drawCurve(HDC hdc, Curve curve)
{
		curveAlgorithm->draw(hdc, curve);
}
void Painter::drawCircle(HDC hdc, Circle circle)
{
	circleAlgorithm->draw(hdc, circle);
}
void Painter::drawWindow(HDC hdc, int left, int right, int top, int bottom,COLORREF color)
{
	Line topLine;
	Line bottomLine;
	Line leftLine;
	Line rightLine;
	topLine.color = color;
	topLine.type = 0;
	bottomLine.color = color;
	bottomLine.type = 0;
	leftLine.color = color;
	leftLine.type = 0;
	rightLine.color = color;
	rightLine.type = 0;
	topLine.start = { left, top };
	topLine.end = { right, top };
	bottomLine.start = { left, bottom };
	bottomLine.end = { right, bottom };
	leftLine.start = { left, bottom };
	leftLine.end = { left, top };
	rightLine.start = { right, bottom };
	rightLine.end = { right, top };
	lineAlgorithm->draw(hdc, topLine);
	lineAlgorithm->draw(hdc, bottomLine);
	lineAlgorithm->draw(hdc, leftLine);
	lineAlgorithm->draw(hdc, rightLine);
}

