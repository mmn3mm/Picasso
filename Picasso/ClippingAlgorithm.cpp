#include "ClippingAlgorithm.h"


ClippingAlgorithm::ClippingAlgorithm()
{
}

ClippingAlgorithm::ClippingAlgorithm(int left,int right,int top,int bottom)
{
	this->left = left;
	this->right = right;
	this->top = top;
	this->bottom = bottom;
}
Point ClippingAlgorithm::vIntersect(int x, Line input)
{
	Point output;
	output.x = x;
	output.y = input.start.y + ((x - input.start.x)*(input.end.y - input.start.y) / (input.end.x - input.start.x));
	return output;
}
Point ClippingAlgorithm::hIntersect(int y, Line input)
{
	Point output;
	output.y = y;
	output.x = input.start.x + ((y - input.start.y)*(input.end.x - input.start.x) / (input.end.y - input.start.y));
	return output;
}
Line ClippingAlgorithm::clipp(Line input)
{

	Line output;
	output.fine = false;
	output.start = input.start;
	output.color = input.color;
	output.end = input.end;
	output.type = input.type;
	OutCode out1 = utility(output.start);
	OutCode out2 = utility(output.end);
	while ((out1.All != 0 || out2.All != 0) && !(out1.All & out2.All))
	{
		if (out1.All != 0)
		{
			Point temp;
			if (out1.left)
			{
				temp = vIntersect(left, output);
			}
			else if (out1.right)
			{
				temp = vIntersect(right, output);

			}
			else if (out1.top)
			{
				temp = hIntersect(top, output);
			}
			else if (out1.bottom)
			{
				temp = hIntersect(bottom, output);
			}
			out1 = utility(temp);
			output.start = temp;
		}
		if (out2.All != 0)
		{
			Point temp;
			if (out2.left)
			{
				temp = vIntersect(left, output);
			}
			else if (out2.right)
			{
				temp = vIntersect(right, output);

			}
			else if (out2.top)
			{
				temp = hIntersect(top, output);
			}
			else if (out2.bottom)
			{
				temp = hIntersect(bottom, output);
			}
		
			out2 = utility(temp);
			output.end = temp;
		}
	}
	if (out1.All == 0 && out2.All == 0)
	{
		output.fine = true;
	}
	return output;

}
OutCode ClippingAlgorithm::utility(Point input)
{
	int x = input.x;
	int y = input.y;
	OutCode output;
	output.All = 0;
	if (x < left)
		output.left = 1;
	if (x>right)
		output.right = 1;
	if (y > bottom)
		output.bottom = 1;
	if (y<top)
		output.top = 1;
	return output;

}

ClippingAlgorithm::~ClippingAlgorithm()
{

}
