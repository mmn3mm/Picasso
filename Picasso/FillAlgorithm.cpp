#include "FillAlgorithm.h"


FillAlgorithm::FillAlgorithm()
{
}
FillAlgorithm::FillAlgorithm(HWND hwnd)
{
	this->hwnd = hwnd;
}
void FillAlgorithm::draw(HDC hdc,Point point)
{
	fill(hdc,point);
}
bool FillAlgorithm::check(HDC hdc,Point point,int width,int length)
{
	COLORREF limit = RGB(255, 255, 255);

	bool cond_1 = GetPixel(hdc, point.x, point.y) == limit;
	bool cond_2 = point.x<width && point.x >0;
	bool cond_3 = point.y<length&&point.y>0;
	return cond_1 && cond_2 && cond_3;

}
void FillAlgorithm::fill(HDC hdc, Point point)
{
	COLORREF color = RGB(0,0, 0);
	RECT rect;
	int width, height;

	if (GetClientRect(hwnd, &rect))
	{
		width = rect.right - rect.left;
		height = rect.bottom - rect.top;
	}
	points.push(point);
	while (!points.empty())
	{
	
		point = points.front();
		points.pop();
		if (!check(hdc,point,width,height))
		{
			continue;
		}
		SetPixel(hdc, point.x, point.y, color);
		points.push({ point.x + 1, point.y  });
		points.push({ point.x , point.y - 1  });
		points.push({ point.x , point.y + 1 });
		points.push({ point.x - 1, point.y});
	}
}
FillAlgorithm::~FillAlgorithm()
{
}
