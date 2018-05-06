#include "SimpleAlgorithmDDA.h"


SimpleAlgorithmDDA::SimpleAlgorithmDDA()
{
}


SimpleAlgorithmDDA::~SimpleAlgorithmDDA()
{
}

void SimpleAlgorithmDDA::drawLine(HDC hdc, int xs, int ys, int xe, int ye)
{
		COLORREF color = RGB(255, 0, 0);
		int dy = ye - ys;
		int dx = xe - xs;
		if (dy == 0 && dy == dx){
			SetPixel(hdc, xe, ye, color);
			return;
		}
		/*
		y= m*(x-xs) + ys
		x= (y-ys)/m + xs
		*/
		if (abs(dx) >= abs(dy))
		{
			/*
			If the dy was positive from the beginning, then m will be negative, but after std::swapping the ye is < ys so ys keeps decreasing.*/
			double m = (double)dy / dx;
			if (xe < xs)
			{
				std::swap(xe, xs);
				std::swap(ye, ys);
			}

			double y = ys;
			for (double i = xs; i <= xe; i++)
			{
				y += m;
				SetPixel(hdc, (int)i, (int)round(y), color);
			}

		}
		else
		{
			double m = (double)dx / dy;
			if (ye < ys)
			{
				std::swap(xe, xs);
				std::swap(ye, ys);
			}

			double x = xs;
			for (double i = ys; i <= ye; i++)
			{
				x += m;
				SetPixel(hdc, (int)round(x), (int)i, color);
			}

		}


}
void SimpleAlgorithmDDA::draw(HDC hdc,Line line)
{
	Point start = line.start;
	Point end = line.end;
	drawLine(hdc, start.x, start.y, end.x, end.y);
}