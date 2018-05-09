#pragma once
#include "Curve.h"
#include "Line.h"
#include "LineAlgorithm.h"
using namespace std;

struct Vector2

{

	double x, y;

	Vector2(double x = 0, double y = 0)

	{

		this->x = x;

		this->y = y;

	}

};

struct Vector4

{

	double v[4];

public:

	Vector4(double x = 0, double y = 0, double z = 0, double w = 0)

	{

		v[0] = x;

		v[1] = y;

		v[2] = z;

		v[3] = w;

	}

	Vector4(double a[])

	{

		memcpy(v, a, 4 * sizeof(double));

	}

	double& operator[](int i)

	{

		return v[i];

	}

};

class Matrix4

{

	Vector4 M[4];

public:

	Matrix4(double A[])

	{

		memcpy(M, A, 16 * sizeof(double));

	}

	Vector4& operator[](int i)

	{

		return M[i];

	}

};

Vector4 operator *(Matrix4, Vector4&);


class CurveAlgorithm
{
public:
	CurveAlgorithm();
	enum  CurveAlgorithmType{
		Bezeir,
		Hermite
	};
	double DotProduct(Vector4& a, Vector4& b);
	Vector4 GetHermiteCoeff(double x0, double s0, double x1, double s1);
	void drawHermite(HDC hdc, COLORREF color, Vector2& P0, Vector2& T0, Vector2&P1, Vector2& T1);
	void drawBezeir(HDC, Curve);
	void draw(HDC, Curve);
	~CurveAlgorithm();
};
