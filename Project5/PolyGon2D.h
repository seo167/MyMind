#pragma once
/*
2018-11-8
继承GameObject，用于绘制2D多边形
*/


#include "GameObject.h"
class PolyGon2D:public GameObject
{
public:
	PolyGon2D(HWND _hwnd, int _PointNum,string _name) :GameObject(_hwnd, _name), PointNum(_PointNum){}
	
	void SetPoint(const int * const point, COLORREF color);
	
	void Draw();

	~PolyGon2D();
private:
	int PointNum;
};

