#include "MidpointLineALgorithm.h"


MidpointLineALgorithm::MidpointLineALgorithm()
{
}


MidpointLineALgorithm::~MidpointLineALgorithm()
{
}
void MidpointLineALgorithm::draw(HDC hdc,Line line)
{
	drawLineMidPoint(hdc, line, RGB(255, 0, 0));
}

void MidpointLineALgorithm::drawLineMidPoint(HDC hdc, Line line, COLORREF color = RGB(255, 0, 0))
{
	int xs = line.start.x;
	int ys = line.start.y;
	int xe = line.end.x;
	int ye = line.end.y;
	int dy = ye - ys;
	int dx = xe - xs;
	if (dx == 0 && dx == dy)
	{
		SetPixel(hdc, xs, ys, color);
		return;
	}
	if (abs(dx) >= abs(dy))
	{
		int inc = 1;
		/*
		Di = dx - 2dy
		d>0: -2dy
		d<0: 2(dx-dy)*/
		if (xs > xe)
		{
			std::swap(xe, xs);
			std::swap(ye, ys);
			dx *= -1;
			dy *= -1;
		}
		if (dy<0)
			inc = -1;

		double x = xs;
		double y = ys;
		SetPixel(hdc, xs, ys, color);
		double d = dx - 2 * abs(dy);
		double above = -2 * abs(dy);
		double under = 2 * (dx - abs(dy));
		while (x != xe)
		{
			if (d >= 0)
			{
				x += 1;
				d += above;
			}
			else{
				x += 1;
				y += inc;
				d += under;
			}
			SetPixel(hdc, x, y, color);
		}
	}
	else
	{
		int inc = 1;
		if (ys > ye)
		{
			std::swap(xe, xs);
			std::swap(ye, ys);
			dx *= -1;
			dy *= -1;
		}
		if (dx<0)
			inc = -1;
		double x = xs;
		double y = ys;
		SetPixel(hdc, xs, ys, color);
		double d = 2 * abs(dx) - dy;
		double right = 2 * abs(dx);
		double left = 2 * (-dy + abs(dx));
		while (y != ye)
		{
			if (d < 0)
			{
				d += right;
			}
			else{
				x += inc;

				d += left;
			}
			y += 1;
			SetPixel(hdc, x, y, color);
		}

	}

}
