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
void Painter::drawLine(HDC hdc,Line line)
{
	
		lineAlgorithm->draw(hdc,line);
}
void Painter::setLineAlgorithm(int type)
{
	delete lineAlgorithm;
	if (type == Simple)
		lineAlgorithm = new SimpleAlgorithm();
	else if (type == DDA)
		lineAlgorithm = new SimpleAlgorithmDDA();
	else if (type == MidPoint)
		lineAlgorithm = new MidpointLineALgorithm();

}