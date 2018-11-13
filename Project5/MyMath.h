#pragma once
#include<cmath>
#include<iostream>
using namespace std;

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
	const Vector3D& operator =(const Vector3D& vt3D);
};

inline const Vector3D& operator *(const float& _num, const Vector3D& vt3D) {
	return Vector3D(_num*vt3D.x, _num*vt3D.y,_num*vt3D.z);
}

struct Vector4D {
	Vector3D vt3;
	float w;

	Vector4D(){
		w = 1;
	}

	//构造函数
	Vector4D(float _x, float _y, float _z){
		vt3.x = _x;
		vt3.y = _y;
		vt3.z = _z;
		w = 1;
	}

	Vector4D(const Vector4D& _vt4) {
		*this = _vt4;
	}

	Vector4D(const Vector3D& _vt3) {
		vt3 = _vt3; w = 1;
	}

	const Vector4D operator -(const Vector4D& vt4D)const;
	const Vector4D& operator -=(const Vector4D& vt4D);
	const Vector4D operator +(const Vector4D& vt4D)const;
	Vector4D &operator +=(const Vector4D& vt4D);
	Vector4D &operator *=(const float& num);
	const Vector4D operator *(const float& num)const;
	Vector4D &operator /=(const float& num);
	const Vector4D operator /(const float& num)const;
	const Vector4D& operator =(const Vector4D& vt4D);
};

inline const Vector4D& operator *(const float& _num, const Vector4D& vt4D) {
	return Vector4D(_num*vt4D.vt3.x, _num*vt4D.vt3.y, _num*vt4D.vt3.z);
}

struct Matrix4X4 {
	float m[4][4];

	//默认构造一个零矩阵
	Matrix4X4() {
		memset(m,0,sizeof(float)*4*4);
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

	const Matrix4X4& operator *=(const float& num);
};

struct Matrix3X3 {
	float m[3][3];

	//默认构造一个零矩阵
	Matrix3X3() {
		memset(m,0,sizeof(float)*3*3);
	}

	Matrix3X3(const Matrix3X3& mt3) {
		*this = mt3;
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
	const Matrix3X3 operator +(const Matrix3X3& mt3)const;
	const Matrix3X3 operator -(const Matrix3X3& mt3)const;
	const Matrix3X3 operator*(const Matrix3X3& mt3)const;
	
	const Matrix3X3& operator =(const Matrix3X3& mt3);
	const Matrix3X3& operator +=(const Matrix3X3& mt3);
	const Matrix3X3& operator -=(const Matrix3X3& mt3);
	const Matrix3X3& operator*=(const Matrix3X3& mt3);

	~Matrix3X3() {
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				*(*(m + i) + j)=NULL;
			}
		}
	//	delete[] m;
	}
};

const Matrix3X3 operator*(const float& num,const Matrix3X3& mt3);