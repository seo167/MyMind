#include "PolyGon3D.h"



//设置顶点
void PolyGon3D::SetPoint(const int * const point, MColor color) {
	const int *temp = point;
	int num = 0;
	while (num < PointNum) {
		int x = (*(temp + 0));
		int y = (*(temp + 1));
		int z = (*(temp+2));
		SetObjectPixel3D(x, y,z,color);
		temp += 3;
		++num;
	}
	temp = nullptr;
}

void PolyGon3D::Draw() {
	DrawTriangle();
	//int maxX = (int)(0.5 + (float)(p2.vt3D.y - p1.vt3D.y)*(float)(p3.vt3D.x - p1.vt3D.x) / (float)(p3.vt3D.y - p1.vt3D.y));
	/*Point pArray[3] = {PixVector[0],PixVector[1] ,PixVector[2] };
	int count = PixVector.size();
	int index;
	for (int i = 0; i < count - 1;++i) {
		index = 1;
		for (int j = index; j < count;++j) {
			if (PixVector[j].vt3D.y>PixVector[index].vt3D.y) {
				continue;
			}
			index = j;
		}

		if (index!=i) {
			swap(pArray[i],pArray[index]);
		}
	}

	float m = (pArray[0].vt3D.y - pArray[2].vt3D.y) / (pArray[0].vt3D.x - pArray[2].vt3D.x);
	int b = pArray[2].vt3D.y - m * pArray[2].vt3D.x;
	int x = (int)((pArray[1].vt3D.y - b) / m + 0.5);
	Point p = {pArray[0].color,x,int(pArray[1].vt3D.y)};
	FillBottomTriangle(pArray[0], p, pArray[1], p.color);
	FillTopTriangle(p,pArray[1],pArray[2], p.color);*/
	//	for (int i = 0; i < count;i+=3) {
	//		Point p1 = PixVector[i];//获取第一个点
	//		Point p2 = PixVector[i + 1];//获取第二个点
	//		Point p3 = PixVector[i+2];//获取第三个点
	//		float temp1 = (p2.vt3D.y - p1.vt3D.y);
	//		float temp2 = (p3.vt3D.x - p1.vt3D.x) / (p3.vt3D.y - p1.vt3D.y);
	//		int maxX = (int)(0.5 + temp1 * temp2);
	//		Point p(p1.color,maxX,p2.vt3D.y);
	//		Graphics::DrawBresenhamLine(p3.vt3D.x,p3.vt3D.y,p.vt3D.x,p.vt3D.y,&(p1.color));
	//		//FillTopTriangle(p1, p, p3, p1.color);
	//		//FillBottomTriangle(p1, p, p3, p1.color);
	///*		if (p1.vt3D.y>p2.vt3D.y||p1.vt3D.y==p2.vt3D.y) {
	//			FillTopTriangle(p1, p2, p3, p1.color);
	//		}else {
	//			FillBottomTriangle(p1, p2, p3, p1.color);
	//		}*/	
	//	}

}
