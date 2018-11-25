#pragma once
//*******************
//正方形类,8个点会按顺序进行输入
//*******************
#include "PolyGon3D.h"
class Cube :public PolyGon3D
{
public:
	Cube(const int* m, string _name) :PolyGon3D(24, _name) {
		SetPoint(m,MColor(255,255,255));
	}

	void Draw();

	~Cube();
private:
	int CubePoint[10][3] = {
		{0,1,2},
		{0,2,3},
		{3,6,4},
		{3,0,4},
		{6,7,4},
		{4,5,7},
		{5,1,2},
		{5,7,2},
		{7,2,3},
		{7,6,3}
	};
};

