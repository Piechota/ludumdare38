#pragma once
#include <math.h>

namespace MathConsts
{
	float const PI = 3.14159265359f;
	float const DegToRad = PI / 180.f;
}

struct Vec2
{
	union
	{
		struct
		{
			float x, y;
		};
		float data[2];
	};


	Vec2()
		: x(0.f)
		, y(0.f)
	{}
	Vec2(Vec2 const& v)
		: x(v.x)
		, y(v.y)
	{}
	Vec2(float const x, float const y)
		: x(x)
		, y(y)
	{}

	void Set(float const x, float const y)
	{
		this->x = x;
		this->y = y;
	}
};

struct Vec2i
{
	union
	{
		struct
		{
			int x, y;
		};
		int data[2];
	};

	Vec2i()
		: x(0)
		, y(0)
	{}
	Vec2i(Vec2i const& v)
		: x(v.x)
		, y(v.y)
	{}
	Vec2i(int const x, int const y)
		: x(x)
		, y(y)
	{}
	void operator -=(Vec2i const& v)
	{
		x -= v.x;
		y -= v.y;
	}
};

struct Vec3
{
	union
	{
		struct
		{
			float x, y, z;
		};
		float data[3];
	};


	Vec3()
		: x(0.f)
		, y(0.f)
		, z(0.f)
	{}
	Vec3(Vec3 const& v)
		: x(v.x)
		, y(v.y)
		, z(v.z)
	{}
	Vec3(float const x, float const y, float const z)
		: x(x)
		, y(y)
		, z(z)
	{}

	void Set(float const x, float const y, float const z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}
};

struct Vec4
{
	union
	{
		struct
		{
			float x, y, z, w;
		};
		float data[4];
	};


	Vec4()
		: x(0.f)
		, y(0.f)
		, z(0.f)
		, w(0.f)
	{}
	Vec4(Vec4 const& v)
		: x(v.x)
		, y(v.y)
		, z(v.z)
		, w(v.w)
	{}
	Vec4(float const x, float const y, float const z, float const w)
		: x(x)
		, y(y)
		, z(z)
		, w(w)
	{}

	void Set(float const x, float const y, float const z, float const w)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}
};

struct Matrix3x3
{
	union
	{
		struct
		{
			float m_data[9];
		};
		struct
		{
			Vec3 m_x;
			Vec3 m_y;
			Vec3 m_z;
		};
		struct
		{
			float m_a00, m_a01, m_a02;
			float m_a10, m_a11, m_a12;
			float m_a20, m_a21, m_a22;
		};
	};

	Matrix3x3()
		: m_a00(1.f), m_a01(0.f), m_a02(0.f)
		, m_a10(0.f), m_a11(1.f), m_a12(0.f)
		, m_a20(0.f), m_a21(0.f), m_a22(1.f)
	{}

	Matrix3x3(float const a00, float const a01, float const a02, float const a10, float const a11, float const a12, float const a20, float const a21, float const a22)
		: m_a00(a00), m_a01(a01), m_a02(a02)
		, m_a10(a10), m_a11(a11), m_a12(a12)
		, m_a20(a20), m_a21(a21), m_a22(a22)
	{}

	Matrix3x3(Matrix3x3 const& mat)
		: m_a00(mat.m_a00), m_a01(mat.m_a01), m_a02(mat.m_a02)
		, m_a10(mat.m_a10), m_a11(mat.m_a11), m_a12(mat.m_a12)
		, m_a20(mat.m_a20), m_a21(mat.m_a21), m_a22(mat.m_a22)
	{}

	void SetTranslateRotationSize(Vec2 const translate, Vec2 const rotation, Vec2 const size)
	{
		m_a00 = +rotation.x * size.x;	m_a01 = rotation.y * size.y;	m_a02 = 0.f;
		m_a10 = -rotation.y * size.x;	m_a11 = rotation.x * size.y;	m_a12 = 0.f;
		m_a20 = translate.x;			m_a21 = translate.y;			m_a22 = 1.f;
	}

	void SetOrthogonalMatrix(float const negative, float const positive)
	{
		float const d = 1.f / (negative - positive);
		float const a = -2.f * d;
		float const b = ( negative + positive ) * d;

		m_a00 = a;		m_a01 = 0.f;	m_a02 = 0.f;
		m_a10 = 0.f;	m_a11 = a;		m_a12 = 0.f;
		m_a20 = b;		m_a21 = b;		m_a22 = 1.f;
	}

	static Matrix3x3 GetTranslateRotationSize(Vec2 const translate, Vec2 const rotation, Vec2 const size)
	{
		Matrix3x3 mat;
		mat.m_a00 = +rotation.x * size.x;	mat.m_a01 = rotation.y * size.y;	mat.m_a02 = 0.f;
		mat.m_a10 = -rotation.y * size.x;	mat.m_a11 = rotation.x * size.y;	mat.m_a12 = 0.f;
		mat.m_a20 = translate.x;			mat.m_a21 = translate.y;			mat.m_a22 = 1.f;

		return mat;
	}

	static Matrix3x3 GetOrthogonalMatrix(float const negative, float const positive)
	{
		Matrix3x3 mat;

		float const d = 1.f / (negative - positive);
		float const a = -2.f * d;
		float const b = (negative + positive) * d;

		mat.m_a00 = a;		mat.m_a01 = 0.f;	mat.m_a02 = 0.f;
		mat.m_a10 = 0.f;	mat.m_a11 = a;		mat.m_a12 = 0.f;
		mat.m_a20 = b;		mat.m_a21 = b;		mat.m_a22 = 1.f;

		return mat;
	}
};

struct Matrix4x4
{
	union
	{
		struct
		{
			float m_data[16];
		};
		struct
		{
			Vec4 m_x;
			Vec4 m_y;
			Vec4 m_z;
			Vec4 m_w;
		};
		struct
		{
			float m_a00, m_a01, m_a02, m_a03;
			float m_a10, m_a11, m_a12, m_a13;
			float m_a20, m_a21, m_a22, m_a23;
			float m_a30, m_a31, m_a32, m_a33;
		};
	};

	Matrix4x4()
		: m_a00(1.f), m_a01(0.f), m_a02(0.f), m_a03(0.f)
		, m_a10(0.f), m_a11(1.f), m_a12(0.f), m_a13(0.f)
		, m_a20(0.f), m_a21(0.f), m_a22(1.f), m_a23(0.f)
		, m_a30(0.f), m_a31(0.f), m_a32(0.f), m_a33(1.f)
	{}

	Matrix4x4(Matrix3x3 const& mat3x3)
		: m_a00(mat3x3.m_a00),	m_a01(mat3x3.m_a01),	m_a02(mat3x3.m_a02),	m_a03(0.f)
		, m_a10(mat3x3.m_a10),	m_a11(mat3x3.m_a11),	m_a12(mat3x3.m_a12),	m_a13(0.f)
		, m_a20(mat3x3.m_a20),	m_a21(mat3x3.m_a21),	m_a22(mat3x3.m_a22),	m_a23(0.f)
		, m_a30(0.f),			m_a31(0.f),				m_a32(0.f),				m_a33(1.f)
	{}
};

extern Matrix3x3 Mul(Matrix3x3 const& a, Matrix3x3 const& b);