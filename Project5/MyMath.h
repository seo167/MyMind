#pragma once
#include<cmath>
struct Vector2D {
	float x, y;

	Vector2D() :x(0), y(0) {}

	//构造函数
	Vector2D(float _x,float _y) :x(_x), y(_y) {}

	//向量的模
	const float VectorMag();

	//归一化
	const void Norm();

	//点乘
	const float Dot(const Vector2D& vt2D);

	const Vector2D operator -(const Vector2D& vt2D)const;
	Vector2D operator -=(const Vector2D& vt2D);
	const Vector2D operator +(const Vector2D& vt2D)const;
	Vector2D &operator +=(const Vector2D& vt2D);
	Vector2D &operator *=(const float& num);
	const Vector2D operator *(const float& num)const;
	Vector2D &operator /=(const float& num);
	const Vector2D operator /(const float& num)const;
};

inline const Vector2D& operator *(const float& _num,const Vector2D& vt2D) {
	return Vector2D(_num*vt2D.x,_num*vt2D.y);
}

struct Vector3D {
	float x, y,z;

	Vector3D() :x(0), y(0),z(0) {}

	//构造函数
	Vector3D(float _x, float _y,float _z) :x(_x), y(_y),z(_z) {}

	//向量的模
	const float VectorMag();

	//归一化
	const void Norm();

	//点乘
	const float Dot(const Vector3D& vt3D);

	//叉乘
	const Vector3D& Cross(const Vector3D& vt3D);

	const Vector3D operator -(const Vector3D& vt3D)const;
	Vector3D operator -=(const Vector3D& vt3D);
	const Vector3D operator +(const Vector3D& vt3D)const;
	Vector3D &operator +=(const Vector3D& vt3D);
	Vector3D &operator *=(const float& num);
	const Vector3D operator *(const float& num)const;
	Vector3D &operator /=(const float& num);
	const Vector3D operator /(const float& num)const;
};

inline const Vector3D& operator *(const float& _num, const Vector3D& vt3D) {
	return Vector3D(_num*vt3D.x, _num*vt3D.y,_num*vt3D.z);
}

struct Matrix4X4 {
	float m[4][4];

	//默认构造一个单位矩阵
	Matrix4X4() {
		m[0][0] = 1;
		m[1][1] = 1;
		m[2][2] = 1;
		m[3][3] = 1;

		m[0][1] = m[0][2] = m[0][3] = m[1][0] = m[1][2] = m[1][3] = m[2][0] = m[2][1] = m[2][3]
			= m[3][0] = m[3][1] = m[3][2] = 0;
	}

	Matrix4X4(const float *_m) {
		for (int i = 0; i < 4;++i) {
			for (int j = 0; j < 4;++j) {
				*(*(m + i ) + j) = *(_m + j) + i;
			}
		}
	}

	//矩阵转置
	void Transpose();

	//设置单位矩阵
	void Norm();

	const Matrix4X4& operator *(const float& num);
	
};

struct Matrix3X3 {
	float m[3][3];

	//默认构造一个单位矩阵
	Matrix3X3() {
		m[0][0] = 1;
		m[1][1] = 1;
		m[2][2] = 1;

		m[0][1] = m[0][2] = m[0][3] = m[1][0] = m[1][2] = m[1][3] = m[2][0] = m[2][1] = m[2][3]= 0;
	}

	Matrix3X3(const float *_m) {

		if (_m==nullptr) {
			return;
		}

		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				*(*(m + i) + j) = *(_m + j) + i;
			}
		}
	}

	//矩阵转置
	void Transpose();

	//设置单位矩阵
	void Norm();

	~Matrix3X3() {
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				*(*(m + i) + j)=NULL;
			}
		}
		delete[] m;
	}
};