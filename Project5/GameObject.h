#pragma once
/*
2018-11-8
将画线算法合并到GameObject里面，作为公共函数


*/
#include<Windows.h>
#include<list>
#include<cmath>
#include<string>
using namespace std;

/*
点位置
*/
struct Point {
	int x = 0, y = 0, z = 0;
	COLORREF color;
	Point(COLORREF _color, int _x = 0, int _y = 0, int _z = 0) :x(_x), y(_y), z(_z), color(_color) {
		x = _x;
		y = _y;
		z = _z;
		color = _color;
	}
};

class GameObject
{
public:
	GameObject(HWND _hwnd,string _name);
	//采用DDA画线
	void DrawDDLine(int x0, int y0, int x1, int y1, COLORREF color);
	//采用Bresenham画线
	void DrawBresenhamLine(int x0, int y0, int x1, int y1, COLORREF color);
	
	~GameObject();

public:
	string name;

protected:

	void SetObjectPixel2D(int x, int y,COLORREF color);

	list<Point> PixList;//存储点

	HDC mHdc;
};

