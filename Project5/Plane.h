#pragma once
#include"PolyGon3D.h"
class Plane:public PolyGon3D
{
public:
	Plane(string _name):PolyGon3D(4, _name) {}
	void Draw();
	~Plane();
};

