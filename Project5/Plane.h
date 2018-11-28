#pragma once
#include"PolyGon3D.h"
#include "Camera.h"
class Plane
{
public:
	Plane(const int* _array, const int* _array1, Camera *_camera){
		camera = _camera;
		int m[3][3] = {
			{*_array,*(_array+1),*(_array + 2)},
			{*(_array+3),*(_array + 4),*(_array + 5)},
			{*(_array + 6),*(_array + 7),*(_array + 8)}
		};

		PolyGon3D Tringle1(3,"");
		Tringle1.SetPoint(*m,MColor(255,255,255));
		TriangleArray.push_back(Tringle1);
		int m1[3][3] = {
			{*_array1,*(_array1 + 1),*(_array1 + 2)},
			{*(_array1 + 3),*(_array1 + 4),*(_array1 + 5)},
			{*(_array1 + 6),*(_array1 + 7),*(_array1 + 8)}
		};
		PolyGon3D Tringle2(3, "");
		Tringle2.SetPoint(*m1, MColor(255, 255, 255));
		TriangleArray.push_back(Tringle2);
		SetMatrix();
	}
	inline void Draw() {
		if(TriangleArray[0].CullState==CULLSTATE::DEFAULT)
			TriangleArray[0].Draw();

		if (TriangleArray[1].CullState == CULLSTATE::DEFAULT)
			TriangleArray[1].Draw();
	}

	inline void RotateY(float angle) {
		TriangleArray[0].transform.RotateY(angle);
		TriangleArray[1].transform.RotateY(angle);
		Conversion();
	}
	inline void RotateX(float angle) {
		TriangleArray[0].transform.RotateX(angle);
		TriangleArray[1].transform.RotateX(angle);
		Conversion();
	}
	inline void RotateZ(float angle) {
		TriangleArray[0].transform.RotateZ(angle);
		TriangleArray[1].transform.RotateZ(angle);
		Conversion();
	}
	void CullBack(PolyGon3D& Tringle);
	void Conversion();//进行空间转换
	void ReSetState() {
		for (int i = 0; i < 2;++i) {
			TriangleArray[i].CullState = CULLSTATE::DEFAULT;
		}
	}
	~Plane();
private:
	void SetMatrix();//设置矩阵
private:
	vector<PolyGon3D> TriangleArray;
	Camera *camera;
};

