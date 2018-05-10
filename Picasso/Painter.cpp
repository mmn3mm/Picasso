#include "Painter.h"

using namespace std;
Painter::Painter()
{
	curveAlgorithm = new CurveAlgorithm();
	lineAlgorithm = new LineAlgorithm();
	circleAlgorithm = new CircleAlgorithm();
	fillAlgorithm = new FillAlgorithm(hwnd);
}

Painter::~Painter()
{
}

LineAlgorithm* Painter::getLineAlgorithm()
{
	return this->lineAlgorithm;
}
CircleAlgorithm* Painter::getCircleAlgorithm()
{
	return this->circleAlgorithm;
}
CurveAlgorithm* Painter::getCurveAlgorithm()
{
	return this->curveAlgorithm;
}
FillAlgorithm* Painter::getFillAlgorithm()
{
	return this->fillAlgorithm;
}
void Painter::drawLine(HDC hdc,Line line)
{
	lines.push_back(line);
	lineAlgorithm->draw(hdc,line);
}
void Painter::setHWND(HWND hwnd)
{
	this->hwnd = hwnd;
}
void Painter::fill(HDC hdc, Point point)
{
	fillAlgorithm->draw(hdc, point);
	fillPoints.push_back(point);
	
}
void Painter::drawCurve(HDC hdc, Curve curve)
{
		curves.push_back(curve);
		curveAlgorithm->draw(hdc, curve);
}
void Painter::drawCircle(HDC hdc, Circle circle)
{
	circles.push_back(circle);
	circleAlgorithm->draw(hdc, circle);
}
void Painter::drawWindow(HDC hdc, int left, int right, int top, int bottom,COLORREF color)
{
	Line topLine;
	Line bottomLine;
	Line leftLine;
	Line rightLine;
	topLine.color = color;
	topLine.type = 0;
	bottomLine.color = color;
	bottomLine.type = 0;
	leftLine.color = color;
	leftLine.type = 0;
	rightLine.color = color;
	rightLine.type = 0;
	topLine.start = { left, top };
	topLine.end = { right, top };
	bottomLine.start = { left, bottom };
	bottomLine.end = { right, bottom };
	leftLine.start = { left, bottom };
	leftLine.end = { left, top };
	rightLine.start = { right, bottom };
	rightLine.end = { right, top };
	lineAlgorithm->draw(hdc, topLine);
	lineAlgorithm->draw(hdc, bottomLine);
	lineAlgorithm->draw(hdc, leftLine);
	lineAlgorithm->draw(hdc, rightLine);
}
void Painter::clear(HDC hdc)
{
	for (int i = 0; i <= 685; i++)
	{
		for (int j = 0; j <= 1365; j++)
		{
			SetPixel(hdc, j, i, RGB(255,255,255));
		}
	}
}
void Painter::save(HDC hdc)
{
	freopen("lines.txt", "w", stdout);
	cout << lines.size() << endl;
	for (int i = 0; i < lines.size(); i++)
	{
		cout << lines[i].color << endl;
		cout << lines[i].type << endl;
		cout << lines[i].start.x << " " << lines[i].start.y << " " << lines[i].end.x << " " << lines[i].end.y << endl;
	}
	freopen("circles.txt", "w", stdout);
	cout << circles.size() << endl;
	for (int i = 0; i < circles.size(); i++)
	{
		cout << circles[i].color << endl;
		cout << circles[i].type << endl;
		cout << circles[i].center.x << " " << circles[i].center.y << " " << circles[i].radius.x<<circles[i].radius.y << endl;
	}
	freopen("curves.txt", "w", stdout);
	cout << curves.size() << endl;
	for (int i = 0; i < curves.size(); i++)
	{
		
		cout << curves[i].color << endl;
		cout << curves[i].type << endl;
		for (int j = 0; j < 4; j++)
		{
			cout << curves[i].points[j].x << " " << curves[i].points[j].y << endl;
		}

	}
	freopen("fill.txt", "w", stdout);
	cout << fillPoints.size() << endl;
	for (int i = 0; i < fillPoints.size(); i++)
	{
		cout << fillPoints[i].x << " " << fillPoints[i].y << endl;
		
	}

}

void Painter::load(HDC hdc)
{
	freopen("lines.txt", "r", stdin);
	int size;
	cin >> size;
	lines.clear();
	for (int i = 0; i < size; i++)
	{
		Line line;
		lines.push_back(line);
		cin >> lines[i].color;
		cin >> lines[i].type;
		cin >> lines[i].start.x >> lines[i].start.y >> lines[i].end.x >> lines[i].end.y;
		drawLine(hdc, lines[i]);
	}
	freopen("circles.txt", "r", stdin);
	cin >> size;
	circles.clear();
	for (int i = 0; i < size; i++)
	{
		Circle circle;
		circles.push_back(circle);
		cin >> circles[i].color;
		cin >> circles[i].type ;
		cin >> circles[i].center.x  >> circles[i].center.y  >> circles[i].radius.x >> circles[i].radius.y ;
		drawCircle(hdc, circles[i]);
	}
	freopen("curves.txt", "r", stdin);
	cin >> size;
	curves.clear();
	for (int i = 0; i < size; i++)
	{
		Curve curve;
		curves.push_back(curve);
		cin >> curves[i].color;
		cin >> curves[i].type ;
		for (int j = 0; j < 4; j++)
		{
			curves[i].points.push_back({ 0, 0 });
			
			cin >> curves[i].points[j].x  >> curves[i].points[j].y ;
		}
		drawCurve(hdc, curves[i]);

	}
	freopen("fill.txt", "r", stdin);
	cin >> size;
	fillPoints.clear();
	fillPoints.reserve(size);
	for (int i = 0; i < size; i++)
	{
		fillPoints.push_back({ 0, 0 });
		cin >> fillPoints[i].x >> fillPoints[i].y;
		fill(hdc, fillPoints[i]);
	}
}