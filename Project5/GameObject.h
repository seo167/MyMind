#pragma once
/*
2018-11-8
将画线算法合并到GameObject里面，作为公共函数
2018-11-9
添加图形设备类，将画线算法转移到图形设备
*/
#include<vector>
#include<cmath>
#include<string>
#include"Transform.h"

using namespace std;

#include "Graphics.h"




class GameObject
{
public:
	GameObject(string _name,const Vector4D& _worldPosition);
	
	//局部坐标转换世界坐标
	void LocalToWorld();

	~GameObject();
public:
	string name;
	
	Transform transform;
protected:
	/*
	点位置
	*/
	struct Point {
		Vector3D vt3D;
		MColor color;
		Point(MColor _color, int _x = 0, int _y = 0, int _z = 0) :color(_color) {
			vt3D.x = _x;
			vt3D.y = _y;
			vt3D.z = _z;
			color = _color;
		}

	};

	void SetObjectPixel2D(int x, int y, MColor color);

	vector<Point> PixVector;//存储点,包括变换后的点
	
protected:
	void FillTopTriangle(Point p1,Point p2,Point p3,MColor color);//填充平顶三角形
	void FillBottomTriangle(Point p1, Point p2, Point p3, MColor color);//填充平底三角形

};

