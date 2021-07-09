#pragma once

class Vector3 
{
public:
	Vector3() :m_x(0),m_y(0),m_z(0)
	{
	}
	Vector3(float x, float y, float z) :m_x(x), m_y(y), m_z(z)
	{

	}
	Vector3(const Vector3& vector) :m_x(vector.m_x), m_y(vector.m_y), m_z(vector.m_z)
	{
	}
	static Vector3 lerp(const Vector3& start, const Vector3& end, float delta)
	{
		Vector3 v;
		v.m_x = start.m_x*(1.0f-delta) + end.m_x*(delta);
		v.m_y = start.m_y * (1.0f - delta) + end.m_y * (delta);
		v.m_z = start.m_z * (1.0f - delta) + end.m_z * (delta);

		return v;
	}

	Vector3 operator *(float num)
	{
		return Vector3(m_x*num, m_y * num, m_z * num);
	}
	Vector3 operator +(Vector3 vec)
	{
		return Vector3(m_x + vec.m_x, m_y + vec.m_y, m_z + vec.m_z);
	}
	~Vector3()
	{
	}
public:
	float m_x, m_y, m_z;
};