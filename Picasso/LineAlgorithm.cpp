#include "LineAlgorithm.h"



LineAlgorithm::LineAlgorithm()
{
}

void LineAlgorithm::draw(HDC hdc, Line line)
{

	switch (line.type)
	{
	case Simple:
		drawSimple(hdc, line);
		break;
	case MidPoint: 
		drawMidPoint(hdc, line);
		break;
	case DDA:
			drawDDA(hdc, line);
			break;	
	}
}
void LineAlgorithm::drawSimple(HDC hdc, Line line)
{

	int xs = line.start.x;
	int ys = line.start.y;
	int xe = line.end.x;
	int ye = line.end.y;
	COLORREF color = line.color;
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

void LineAlgorithm::drawMidPoint(HDC hdc, Line line)
{
	COLORREF color = line.color;
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

void LineAlgorithm::drawDDA(HDC hdc, Line line)
{
	int xs = line.start.x;
	int ys = line.start.y;
	int xe = line.end.x;
	int ye = line.end.y;
	COLORREF color = line.color;
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

LineAlgorithm::~LineAlgorithm()
{
}
