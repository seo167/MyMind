#pragma once
/*
	2018-11-11 加入转换类
*/

#include "MyMath.h"
#include "Graphics.h"
#include<vector>
using namespace std;
/*
点位置
*/
struct Point {
	Vector3D vt3D;
	MColor color;
	Point() {}

	Point(MColor _color, int _x = 0, int _y = 0, int _z = 0) :color(_color) {
		vt3D.x = _x;
		vt3D.y = _y;
		vt3D.z = _z;
		color = _color;
	}
};

class Transform
{
private:
	vector<Point> PointArray;
	vector<Vector4D> ChangePositionArray;//转换后坐标的数组
public:
	Matrix4X4 WorldMatrix;//世界坐标
	Vector4D localPosition;//局部坐标
	Matrix4X4 CameraMatrix;//相机空间
	Matrix4X4 PerspectiveMatrix;//投影矩阵
	Matrix4X4 ViewMatrix;//屏幕矩阵
public:
	Transform();
	~Transform();
	//加入点
	inline void AddPoint(Point _p) {
		PointArray.push_back(_p);
	}

	inline vector<Point> GetPointArray()const {
		return PointArray;
	}

	void Rotate2D(const Vector2D& vct);//2D旋转
	void LocalToWorld();
	void WorldToCamera();
	void CameraToPerspective();//透视转换
	void PerspectiveToView();//屏幕转换
	void Move(const Vector3D& vt3d);
};

