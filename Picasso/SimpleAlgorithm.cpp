#include "SimpleAlgorithm.h"


SimpleAlgorithm::SimpleAlgorithm()
{
}


SimpleAlgorithm::~SimpleAlgorithm()
{
}

void SimpleAlgorithm::drawLine(HDC hdc, int xs, int ys, int xe, int ye)
{
	
		COLORREF color = RGB(0, 0, 0);
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
		if (abs(dx) > abs(dy))
		{
			double y;
			/*
			If the dy was positive from the beginning, then m will be negative, but after swapping the ye is < ys so ys keeps decreasing.*/
			double m = (double)dy / dx;
			if (xe < xs)
			{
				std::swap(xe, xs);
				std::swap(ye, ys);
			}
			for (double i = xs; i < xe; i++)
			{
				y = m * (i - xs) + ys;
				y = round(y);
				SetPixel(hdc, (int)i, (int)y, color);
			}

		}
		else
		{
			double x;
			double m = (double)dx / dy;
			if (ye < ys)
			{
				std::swap(xe, xs);
				std::swap(ye, ys);
			}
			for (double i = ys; i < ye; i++)
			{
				x = m * (i - ys) + xs;
				x = round(x);
				SetPixel(hdc, (int)x, (int)i, color);
			}

		}

	
}
void SimpleAlgorithm::draw(HDC hdc,Line line)
{
	Point start = line.start;
	Point end = line.end;
	drawLine(hdc, start.x, start.y, end.x, end.y);
}