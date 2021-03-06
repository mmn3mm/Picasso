
#include <Windows.h> //responsible for all the functions of windows APIs
#include <iostream>
#include "FillAlgorithm.h"
#include "Circle.h"
#include "Curve.h"
#include <vector>
#include "resource.h"
#include "ClippingAlgorithm.h"
#include "Painter.h"


using namespace std;
bool draw;
LPARAM first;
int condition = -1;
int type = 0;
Painter painter;
vector<Line> lines;
vector<Point> points;
LRESULT WINAPI WndProc(HWND hwnd, UINT MSG, WPARAM wp, LPARAM lp)
{
	HDC hdc;
	switch (MSG)
	{
	case WM_LBUTTONDOWN:
		hdc = GetDC(hwnd);
		if (condition == -1)
			MessageBoxA(hwnd, "Please choose an option from above!", "Error", MB_OK);
		else if (condition == 0  )
		{

			if (draw)
			{
				Line line;
				line.color = RGB(10, 255, 1);
				line.start.x = LOWORD(first);
				line.start.y = HIWORD(first);
				line.end.x = LOWORD(lp);
				line.end.y = HIWORD(lp);
				line.type = type;
				painter.drawLine(hdc,line);
				lines.push_back(line);
				draw = false;
			}
			else
			{
				draw = true;
			}
			first = lp;
		}
		else if (condition == 1)
		{
			if (draw)
			{
				Circle circle({ LOWORD(first), HIWORD(first) }, { LOWORD(lp), HIWORD(lp) });
				circle.color = RGB(10, 255, 1);
				circle.type = type;
				painter.drawCircle(hdc, circle);
				draw = false;
			}
			else
			{
				draw = true;
			}
			first = lp;
		}
		else if (condition == 2)
		{
			painter.fill(hdc, { LOWORD(lp), HIWORD(lp) });

		}
		else if (condition == 3)
		{
			if (draw)
			{
				int left = LOWORD(first);
				int right = LOWORD(lp);
				int top = HIWORD(first);
				int bottom = HIWORD(lp);
				ClippingAlgorithm clippingAlgorithm(left, right, top, bottom);
				for (int i = 0; i < lines.size(); i++)
				{
					Line oldLine = lines[i];
					oldLine.color = RGB(255,255,255);
					painter.drawLine(hdc,oldLine);		
					Line line = clippingAlgorithm.clipp(lines[i]);
					if (line.fine)
						painter.drawLine(hdc, line);
				}
				painter.drawWindow(hdc, left, right, top, bottom, RGB(0, 0, 0));
				draw = false;
			}
			else
			{
				draw = true;
			}
			first = lp;

		}
		else if (condition == 4)
		{
			points.push_back({ LOWORD(lp), HIWORD(lp) });

			if (points.size()==4)
			{
				Curve curve;
				curve.color = RGB(10, 255, 1);
				curve.type = type;
				curve.points = points;
				painter.drawCurve(hdc, curve);
				points.clear();
			}
			
		}
		first = lp;
		ReleaseDC(hwnd, hdc);
		break;
	case WM_RBUTTONDOWN:
		break;
	case WM_CLOSE:
		DestroyWindow(hwnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_COMMAND:

	{
			draw = false;
			switch (LOWORD(wp))

			{
			case ID_LINE:
				condition = 0; //Break is not written on purpose, in order to auto set the type.
			case ID_Simple:
				if (condition == 0) //If mistakenly changed type
					type = 0;
				break;
			case ID_DDA:
				if (condition == 0)
					type = 1;
				break;
			case ID_MidPoint:
				if (condition == 0)
					type = 2;
					break;
			case ID_CIRCLE:
				condition = 1; //Break is not written on purpose, in order to auto set the type.
			case ID_CIRCLESIMPLE:
				if (condition == 1)
					type = 0;
				break;
			case ID_CIRCLEPolar:
				if (condition == 1)
					type = 1;
				break;
			case ID_CIRCLEMidPoint:
				if (condition == 1)
					type = 2;
				break;
			case ID_Fill:
				condition = 2;
				break;
			case ID_CLIP:
				condition = 3;
				break;
			case ID_Curve:
				condition = 4;
			case ID_Bezeir:
				type = 0;
				break;
			case ID_Hermite:
				type = 1;
				break;
			case ID_Save:
				painter.save(GetDC(hwnd));
				painter.clear(GetDC(hwnd));
				break;
			case ID_Load:
				painter.clear(GetDC(hwnd));
				painter.load(GetDC(hwnd));
				break;
			}
	} 
		break;
	default:
		return DefWindowProc(hwnd, MSG, wp, lp);
		break;
	}
}
void initialize(HINSTANCE hi)
{
	WNDCLASS myClass;
	myClass.hInstance = hi;
	myClass.cbClsExtra = myClass.cbWndExtra = 0;
	myClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	myClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	myClass.hIcon = LoadIcon(NULL, IDI_WINLOGO);
	myClass.lpszClassName = L"MyClass";
	myClass.lpszMenuName = MAKEINTRESOURCE(IDR_MYMENU);
	myClass.style = CS_HREDRAW | CS_VREDRAW;
	myClass.lpfnWndProc = WndProc;
	RegisterClass(&myClass);
	HWND hwnd = CreateWindow(L"MyClass", L"mn3m", WS_OVERLAPPEDWINDOW, 0, 0, 800, 600, NULL, NULL, hi, NULL);
	painter.getFillAlgorithm()->hwnd = hwnd;
	ShowWindow(hwnd, SW_SHOW);
}
int APIENTRY WinMain(HINSTANCE hi, HINSTANCE, LPSTR cmd, int n)
{
	initialize(hi);
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}