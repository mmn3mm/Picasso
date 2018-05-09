#pragma once
#include "Line.h"
union OutCode{
	unsigned All : 4;
	struct
	{
		unsigned left : 1;
		unsigned top : 1;
		unsigned right : 1;
		unsigned bottom : 1;
	};
};
class ClippingAlgorithm
{
public:
	int left, right, top, bottom;
	OutCode utility(Point );
	Point vIntersect(int , Line );
	Point hIntersect(int , Line );
	Line clipp(Line input);
	ClippingAlgorithm();
	ClippingAlgorithm(int ,int,int,int);
	~ClippingAlgorithm();
};

