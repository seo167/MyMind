#include "Cube.h"

void Cube::Draw() {
	vector<Point> temp= transform.GetPointArray();
	for (int i = 0; i < 10;++i) {
		for (int j = 0; j < 2;++j) {
			int num1 = CubePoint[i][j];
			int num2 = CubePoint[i][j+1];
			Graphics::DrawBresenhamLine(temp[num1].vt3D.x, temp[num1].vt3D.y, temp[num2].vt3D.x, temp[num2].vt3D.y,&temp[num2].color);
			if (j+1>=2) {
				num1 = CubePoint[i][0];
				num2= CubePoint[i][2];
				Graphics::DrawBresenhamLine(temp[i].vt3D.x, temp[num1].vt3D.y, temp[num2].vt3D.x, temp[num2].vt3D.y, &temp[num2].color);
			}
		}

	}
}

Cube::~Cube(){}
