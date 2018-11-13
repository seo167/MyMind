#include "PolyGon2D.h"

void PolyGon2D::SetPoint(const int * const point,MColor color) {
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
	vector<Point>::iterator temp1= PixVector.begin();//x0，y0点
	vector<Point>::iterator temp2= PixVector.begin();//x1，y1点

	while (true) {
		++temp2;
		if (temp2== PixVector.end()) {
			break;
		}
		Graphics::DrawBresenhamLine(temp1->vt3D.x, temp1->vt3D.y, temp2->vt3D.x, temp2->vt3D.y, &(temp1->color));
		++temp1;
	}
	temp2 = PixVector.begin();

	Graphics::DrawBresenhamLine(temp1->vt3D.x, temp1->vt3D.y, temp2->vt3D.x, temp2->vt3D.y, &(temp1->color));

	int count = PixVector.size();
	if (count%3==0) {
		
		for (int i = 0; i < count;i+=3) {
			Point p1 = PixVector[i];//获取第一个点
			Point p2 = PixVector[i + 1];//获取第二个点
			Point p3 = PixVector[i+2];//获取第三个点
			FillBottomTriangle(p1,p2,p3, p1.color);
		}
	}
	
}

PolyGon2D::~PolyGon2D(){
	
}
