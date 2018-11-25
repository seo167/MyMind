#include "PolyGon3D.h"

void PolyGon3D::SetPoint(const int * const point, MColor color) {
	const int *temp = point;
	int num = 0;
	while (num < PointNum) {
		int x = (*(temp + 0));
		int y = (*(temp + 1));
		int z = (*(temp + 2));
		SetObjectPixel3D(x, y,z, color);
		temp += 3;
		++num;
	}
	temp = nullptr;
}

void PolyGon3D::Draw() {
	DrawTriangle();
}

PolyGon3D::~PolyGon3D(){}
