#include "Camera.h"

void Camera::SetLookAt(Matrix4X4 *cMat,Vector3D eye, Vector3D at, Vector3D up) {
	n = at-eye;
	n.Norm();
	
	u = up.Cross(n);
	u.Norm();
	v = n.Cross(u);
	v.Norm();
	pos.vt3 = eye;
	InitTMat();
	InitRMat();
	//计算相机变换矩阵
	*cMat = tMat * rMat;
}

void Camera::SetPerspective(Matrix4X4 *PerspectiveMat) {
	int ar = Width / Height;//获取宽高比
	float fax=1/tanf(fov*0.5);//获取半角
	PerspectiveMat->m[0][0] = int(1 / (ar*fax));
	PerspectiveMat->m[1][1] = int(1 / (fax));
	PerspectiveMat->m[2][2] = int(-far_z-near_z / near_z - far_z);
	PerspectiveMat->m[2][3] = int(2*far_z*near_z/near_z-far_z);
	PerspectiveMat->m[3][2] = 1;
}

void Camera::SetView(Matrix4X4 *ViewMat) {
	float alpha = Width / 2;
	float beta = Height / 2;

	ViewMat->m[0][0] = alpha;
	ViewMat->m[1][1] = -beta;
	ViewMat->m[2][2] = far_z - near_z;
	ViewMat->m[3][0] = alpha;
	ViewMat->m[32][1] = beta;
	ViewMat->m[3][3] = 1;
}


void Camera::InitTMat(){
	tMat.m[0][0] = tMat.m[1][1]
		= tMat.m[2][2] = tMat.m[3][3]
		= 1;
	tMat.m[3][0] = (-pos.vt3.x);
	tMat.m[3][1] = (-pos.vt3.y);
	tMat.m[3][2] = (-pos.vt3.z);

}

void Camera::InitRMat(){
	rMat.m[0][0] = u.x;rMat.m[0][1] = u.y;rMat.m[0][2] = u.z;
	rMat.m[1][0] = v.x;rMat.m[1][1] = v.y;rMat.m[1][2] = v.z;
	rMat.m[2][0] = n.x; rMat.m[2][1] = n.y; rMat.m[2][2] = n.z;
	rMat.m[3][3] = 1;
}


Camera::~Camera(){

}
