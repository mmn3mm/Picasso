#pragma once
#include "Shape.h"
#include <queue>
class FillAlgorithm
{
public:
	FillAlgorithm();
	FillAlgorithm(HWND);
	HWND hwnd;
	std::queue<Point> points;
	void fill(HDC, Point);
	bool check(HDC, Point, int, int);
	void draw(HDC,Point);
	~FillAlgorithm();
};

