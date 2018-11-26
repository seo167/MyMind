#include "Plane.h"

void Plane::Draw(){
	//绘制两个三角形
	vector<Point> temp = transform.GetPointArray();
	Graphics::DrawBresenhamLine(temp[0].vt3D.x,temp[0].vt3D.y,temp[1].vt3D.x,temp[1].vt3D.y,&temp[0].color);
	Graphics::DrawBresenhamLine(temp[1].vt3D.x, temp[1].vt3D.y, temp[2].vt3D.x, temp[2].vt3D.y, &temp[0].color);
	Graphics::DrawBresenhamLine(temp[0].vt3D.x, temp[0].vt3D.y, temp[2].vt3D.x, temp[2].vt3D.y, &temp[0].color);

	Graphics::DrawBresenhamLine(temp[0].vt3D.x, temp[0].vt3D.y, temp[3].vt3D.x, temp[3].vt3D.y, &temp[0].color);
	Graphics::DrawBresenhamLine(temp[3].vt3D.x, temp[3].vt3D.y, temp[2].vt3D.x, temp[2].vt3D.y, &temp[0].color);
	Graphics::DrawBresenhamLine(temp[0].vt3D.x, temp[0].vt3D.y, temp[2].vt3D.x, temp[2].vt3D.y, &temp[0].color);
}


Plane::~Plane()
{
}
