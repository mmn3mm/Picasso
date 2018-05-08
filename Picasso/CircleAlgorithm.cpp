#include "CircleAlgorithm.h"
#include <math.h>

CircleAlgorithm::CircleAlgorithm()
{
}
void CircleAlgorithm::draw(HDC hdc, Circle circle)
{

	switch (circle.type)
	{
	case Simple:
		drawCircleQuadratic(hdc, circle);
		break;
	case MidPoint:
		drawCircleMidPoint(hdc, circle);
		break;
	case Polar:
		drawPolar(hdc, circle);
		break;
	}
}
void CircleAlgorithm::draw8Points(HDC hdc, int xc, int yc, int x, int y, COLORREF color){
	SetPixel(hdc, xc + x, yc + y, color);
	SetPixel(hdc, xc + x, yc - y, color);
	SetPixel(hdc, xc - x, yc + y, color);
	SetPixel(hdc, xc - x, yc - y, color);
	SetPixel(hdc, xc + y, yc + x, color);
	SetPixel(hdc, xc + y, yc - x, color);
	SetPixel(hdc, xc - y, yc + x, color);
	SetPixel(hdc, xc - y, yc - x, color);
}
void CircleAlgorithm::drawCircleMidPoint(HDC hdc, Circle circle)
{
	int xe = circle.center.x;
	int ye = circle.center.y;
	int xs = circle.radius.x;
	int ys = circle.radius.y;
	COLORREF color = circle.color;
	int R = circle.dist(circle.radius,circle.center);
	int x = 0, y = R;
	int d = 1 - R;
	draw8Points(hdc, xs, ys, 0, 0, color);
	while (x < y)
	{
		if (d < 0){
			d += 2 * x + 3;
		}
		else
		{
			d += 2 * x - 2 * y + 5;
			y--;
		}
		x++;
		draw8Points(hdc, xs, ys, x, y, color);
	}
}
void CircleAlgorithm::drawCircleQuadratic(HDC hdc, Circle circle)
{
	int xe = circle.center.x;
	int ye = circle.center.y;
	int xs = circle.radius.x;
	int ys = circle.radius.y;
	COLORREF color = circle.color;
	int R = circle.dist(circle.radius, circle.center);
	int x = 0;
	int y = R;
	while (x < y)
	{

		draw8Points(hdc, xs, ys, x, y, color);
		x++;
		y = round(sqrt((double)(R*R) - (x*x)));
	}

}
void CircleAlgorithm::drawPolar(HDC hdc, Circle circle)
{
	int xe = circle.center.x;
	int ye = circle.center.y;
	int xs = circle.radius.x;
	int ys = circle.radius.y;
	COLORREF color = circle.color;
	int R = circle.dist(circle.radius, circle.center); 
	int x = R, y = 0;
	double theta = 0, d = (1.0 / R);
	while (x >y)
	{
		theta += d;
		x = round(R*cos(theta));
		y = round(R*sin(theta));
		draw8Points(hdc,xe,ye,x,y, color);
	}
}
CircleAlgorithm::~CircleAlgorithm()
{
}
