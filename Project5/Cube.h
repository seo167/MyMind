#pragma once
//*******************
//正方形类
//*******************
#include "Plane.h"
#include"Camera.h"
class Cube
{
public:
	Cube(Camera *_cam,string _name, bool _isCull=true):isCull(_isCull){
		camera = _cam;
		InitCube();
	}
	void Conversion();//转换
	void Draw();
	void RotateY(float Angle);
	void RotateX(float Angle);
	void RotateZ(float Angle);
	inline void ReSetCullState() {
		for (int i = 0; i < 6;++i) {
			planeArray[i].ReSetState();
		}
	}
	~Cube();
private:
	void InitCube();
private:
	vector<Plane> planeArray;
	Camera *camera;
	bool isCull;//判断是否开启裁剪
	
};

