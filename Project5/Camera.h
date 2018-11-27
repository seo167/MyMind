#pragma once
#include"MyMath.h"
#include"Common.h"
class Camera
{
public:
	Vector4D pos;//相机位置
public:
	//角度，近裁剪，远裁剪
	Camera(float _fov,float _near_z, float _far_z) : 
		fov(_fov),near_z(_near_z), far_z(_far_z) {
		ar = float(WIDTH)/ float(HEIGHT);
		Width = 2;
		Height = 2 / ar;
		//角度转弧度
		float edg = (90 / 2 * 3.14);
		distance = 0.5*Width*tan(edg / 180);
	}

	//设置相机朝向(摄像机位置，目标位置，视距)
	void SetLookAt(Vector3D eye, Vector3D _target);
	//获取相机空间矩阵
	void SetCameraMatrix(Matrix4X4 *cMat) {
		//计算相机变换矩阵
		*cMat = tMat * rMat;
	}

	//设置投影坐标
	void SetPerspective(Matrix4X4 *PerspectiveMat);

	//设置屏幕转换坐标
	void SetView(Matrix4X4 *ViewMat);

	inline const float GetFov()const {
		return fov;
	}

	inline const float GetNearZ()const {
		return near_z;
	}

	inline const float GetFarZ()const {
		return far_z;
	}

	~Camera();
private:
	void InitTMat();//初始化平移矩阵
	void InitRMat();//初始化旋转矩阵
private:
	Vector3D u, v, n;//摄像机三个方向
	float fov;//水平视野和垂直视野的角度
	float near_z, far_z;//远，近裁剪面
	
	Matrix4X4 tMat;//平移矩阵
	Matrix4X4 rMat;//旋转矩阵
	int Width;//投影宽
	int Height;//投影高
	float distance;//视距
	float ar;//宽高比
	Vector4D target;
};

