#pragma once
/*
2018-11-8
将画线算法合并到GameObject里面，作为公共函数
2018-11-9
添加图形设备类，将画线算法转移到图形设备
*/

#include<cmath>
#include<string>
#include"Transform.h"


class GameObject
{
public:
	GameObject(string _name);
	~GameObject();
public:
	string name;
	
	Transform transform;
protected:
	
	void SetObjectPixel2D(int x, int y, MColor color);
	
	unsigned int TriangleCount;//三角形个数

	void DrawTriangle();

protected:
	void FillTopTriangle(Point p1,Point p2,Point p3,MColor color);//填充平顶三角形
	void FillBottomTriangle(Point p1, Point p2, Point p3, MColor color);//填充平底三角形

};

