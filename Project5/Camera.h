#pragma once
#include"MyMath.h"
class Camera
{
public:
	Camera(int _Width,int _Height,float _fov,
		float _near_z, float _far_z) : 
		fov(_fov),Width(_Width),Height(_Height),near_z(_near_z), far_z(_far_z) {

	}

	//设置相机朝向(摄像机位置，观察点的位置，向上的向量)
	void SetLookAt(Matrix4X4 *cMat,Vector3D eye,Vector3D at,Vector3D up);

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
	float fov;//水平视野和垂直视野
	float near_z, far_z;//远，近裁剪面
	Vector4D pos;//相机位置
	Matrix4X4 tMat;//平移矩阵
	Matrix4X4 rMat;//旋转矩阵
	int Width;//投影宽
	int Height;//投影高
};

