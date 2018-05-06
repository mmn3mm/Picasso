
#include <Windows.h> //responsible for all the functions of windows APIs
#include <iostream>
#include <vector>
#include "resource.h"
#include "Painter.h"
using namespace std;
bool draw;
LPARAM first;
int condition = -1;

Painter painter;
LRESULT WINAPI WndProc(HWND hwnd, UINT MSG, WPARAM wp, LPARAM lp)
{
	int x, y, ans;
	HDC hdc;
	switch (MSG)
	{
	case WM_LBUTTONDOWN:
		hdc = GetDC(hwnd);
		if (condition == -1||painter.getLineAlgorithm() == NULL)
			MessageBoxA(hwnd, "Please choose an option from above!", "Error", MB_OK);
		else if (condition == 0  )
		{

			if (draw)
			{
				Line line;
				line.start.x = LOWORD(first);
				line.start.y = HIWORD(first);
				line.end.x = LOWORD(lp);
				line.end.y = HIWORD(lp);
				painter.drawLine(hdc,line);
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
			switch (LOWORD(wp))

			{
			case ID_DRAW:
				condition = 0;
			case ID_Simple:
				painter.setLineAlgorithm(ID_Simple);
				break;
			case ID_DDA:
				painter.setLineAlgorithm(ID_DDA);
				break;
			case ID_MidPoint:
				painter.setLineAlgorithm(ID_MidPoint);
				break;

			}
	} break;


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