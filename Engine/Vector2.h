#pragma once

class Vector2
{
public:
	Vector2() :m_x(0), m_y(0)
	{
	}
	Vector2(float x, float y) :m_x(x), m_y(y)
	{

	}
	Vector2(const Vector2& vector) :m_x(vector.m_x), m_y(vector.m_y)
	{
	}

	Vector2 operator *(float num)
	{
		return Vector2(m_x * num, m_y * num);
	}
	Vector2 operator +(Vector2 vec)
	{
		return Vector2(m_x + vec.m_x, m_y + vec.m_y);
	}
	~Vector2()
	{
	}
public:
	float m_x, m_y;
};