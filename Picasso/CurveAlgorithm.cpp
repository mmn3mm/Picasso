#include "CurveAlgorithm.h"

CurveAlgorithm::CurveAlgorithm()
{
}

Vector4 operator *(Matrix4 M, Vector4& b)

{

	Vector4 res;

	for (int i = 0; i<4; i++)

	for (int j = 0; j<4; j++)

		res[i] += M[i][j] * b[j];

	return res;

}
double CurveAlgorithm::DotProduct(Vector4& a, Vector4& b){

	return a[0] * b[0] + a[1] * b[1] + a[2] * b[2] + a[3] * b[3];

}
Vector4 CurveAlgorithm::GetHermiteCoeff(double x0, double s0, double x1, double s1)

{

	static double H[16] = { 2, 1, -2, 1, -3, -2, 3, -1, 0, 1, 0, 0, 1, 0, 0, 0 };

	static Matrix4 basis(H);

	Vector4 v(x0, s0, x1, s1);

	return basis*v;

}


void CurveAlgorithm::drawHermite(HDC hdc,COLORREF color, Vector2& P0, Vector2& T0, Vector2&P1, Vector2& T1)
{
	Vector4 xcoeff = GetHermiteCoeff(P0.x, T0.x, P1.x, T1.x);
	Vector4 ycoeff = GetHermiteCoeff(P0.y, T0.y, P1.y, T1.y);
	Point curr;

	double dt = (double) 1.0 / 30000.0;

	for (double t = 0; t <= 1; t += dt)  {

		Vector4 vt;

		vt[3] = 1;

		for (int i = 2; i >= 0; i--)

			vt[i] = (double)vt[i + 1] * t;

		int x = round(DotProduct(xcoeff, vt));

		int y = round(DotProduct(ycoeff, vt));

		if (t == 0)
		{
			MoveToEx(hdc, x, y, NULL);

		}
		else
		{
			Line line;
			line.type = 2;
			line.color = color;
			line.start = curr;
			line.end = { x, y };
			LineAlgorithm lineAlgorithm;
			lineAlgorithm.drawDDA(hdc, line);
		}
		curr = { x, y };

	}
}
void CurveAlgorithm::drawBezeir(HDC hdc, Curve curve)
{

	Point first = curve.points[0];
	Point second = curve.points[1];
	Point third = curve.points[2];
	Point fourth = curve.points[3];

	Vector2 P0(first.x, first.y);

	Vector2 P1(second.x, second.y);

	Vector2 P2(third.x, third.y);

	Vector2 P3(fourth.x,fourth.y);

	Vector2 T0(3 * (P1.x - P0.x), 3 * (P1.y - P0.y));

	Vector2 T1(3 * (P3.x - P2.x), 3 * (P3.y - P2.y));

	drawHermite(hdc,curve.color, P0, T0, P3, T1);
}
void CurveAlgorithm::draw(HDC hdc, Curve curve)
{

	switch (curve.type)
	{
	case Bezeir:
		drawBezeir(hdc, curve);
		break;
	case Hermite:
		Vector2 P0(curve.points[0].x, curve.points[0].y);

		Vector2 T0(curve.points[1].x, curve.points[1].y);

		Vector2 T1(curve.points[2].x, curve.points[2].y);

		Vector2 P1(curve.points[3].x, curve.points[1].y);
		drawHermite(hdc,curve.color, P0, T0, P1, T1);
		break;
	}
}

CurveAlgorithm::~CurveAlgorithm()
{
}
