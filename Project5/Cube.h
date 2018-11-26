#pragma once
//*******************
//正方形类,8个点会按顺序进行输入
//*******************
#include "Plane.h"
#include"Camera.h"
class Cube
{
public:
	Cube(Camera *_cam,string _name){
		planeArray.push_back(Plane("Plane1"));
		planeArray.push_back(Plane("Plane2"));
		planeArray.push_back(Plane("Plane3"));
		planeArray.push_back(Plane("Plane4"));
		planeArray.push_back(Plane("Plane5"));
		planeArray.push_back(Plane("Plane6"));
		camera = _cam;
		for (int i = 0; i < 6; ++i) {
			camera->SetCameraMatrix(&(planeArray[i].transform.CameraMatrix));
			camera->SetPerspective(&(planeArray[i].transform.PerspectiveMatrix));
			camera->SetView(&(planeArray[i].transform.ViewMatrix));
		}
		
		InitCube();
	}
	void Change();//转换
	void Draw();
	void RotateY(float Angle);
	~Cube();
private:
	void InitCube();
private:
	vector<Plane> planeArray;
	Camera *camera;
	
};

