#include "PolyGon2D.h"

void PolyGon2D::SetPoint(const int * const point,COLORREF color) {
	const int *temp = point;
	int num = 0;
	while (num<PointNum) {
		int x=(*(temp + 0));
		int y= (*(temp + 1));
		SetObjectPixel2D(x,y,color);
		temp += 2;
		++num;
	}
	temp = nullptr;
}

void PolyGon2D::Draw() {
	list<Point>::iterator temp1=PixList.begin();//x0£¬y0µã
	list<Point>::iterator temp2=PixList.begin();//x1£¬y1µã
	
	
	while (true) {
		++temp2;
		if (temp2== PixList.end()) {
			break;
		}
		DrawBresenhamLine(temp1->x,temp1->y,temp2->x,temp2->y,temp1->color);
		++temp1;
	}
	temp2 = PixList.begin();

	DrawBresenhamLine(temp1->x, temp1->y, temp2->x, temp2->y, temp1->color);
}

PolyGon2D::~PolyGon2D(){
	
}
