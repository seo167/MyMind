#pragma once
/*
	2018-11-11 加入转换类
*/

#include "MyMath.h"

class Transform
{
public:
	Vector4D Position;//世界坐标
	Vector4D localPosition;//局部坐标
	Vector4D changePosition;//转换后的坐标
public:
	Transform();
	~Transform();
	void Rotate2D(const Vector2D& vct);//2D旋转
	inline void LocalToWorld() {
		changePosition = localPosition + Position;
	}
	
};

