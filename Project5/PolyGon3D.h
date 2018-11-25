#pragma once

#include "GameObject.h"
class PolyGon3D :public GameObject
{
public:
	PolyGon3D(int _PointNum, string _name, const Vector4D& vt4) :GameObject(_name, vt4), PointNum(_PointNum) {}
	void SetPoint(const int * const point, MColor color);
	~PolyGon3D() {
		
	}
	void Draw();
private:
	int PointNum;
};

