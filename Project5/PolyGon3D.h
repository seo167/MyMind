#pragma once
#include "GameObject.h"
class PolyGon3D:public GameObject
{
public:
	PolyGon3D(int _PointNum, string _name) :GameObject(_name), PointNum(_PointNum) {}
	void SetPoint(const int * const point, MColor color);
	virtual void Draw();
	~PolyGon3D();
private:
	int PointNum;
};

