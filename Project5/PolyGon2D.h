#pragma once
/*
2018-11-8
继承GameObject，用于绘制2D多边形
*/


#include "GameObject.h"
class PolyGon2D:public GameObject
{
public:
	PolyGon2D(int _PointNum,string _name,const Vector4D& vt4) :GameObject( _name, vt4), PointNum(_PointNum){}
	
	void SetPoint(const int * const point, MColor color);
	
	void Draw();

	~PolyGon2D();
private:
	int PointNum;
};

