#pragma once
/*
2018-11-8
将画线算法合并到GameObject里面，作为公共函数
2018-11-9
添加图形设备类，将画线算法转移到图形设备
*/
#include<list>
#include<cmath>
#include<string>
using namespace std;

/*
点位置
*/
struct Point {
	int x = 0, y = 0, z = 0;
	//COLORREF color;
	//Point(COLORREF _color, int _x = 0, int _y = 0, int _z = 0) :x(_x), y(_y), z(_z), color(_color) {
	//	x = _x;
	//	y = _y;
	//	z = _z;
	//	color = _color;
	//}
};

//class GameObject
//{
//public:
//	GameObject(string _name);
//	
//	~GameObject();
//
//public:
//	string name;
//
//protected:
//	
//	void SetObjectPixel2D(int x, int y,COLORREF color);
//
//	list<Point> PixList;//存储点
//};

