/*
	Copyright (c) 2018 by CanftIn <wwc7033@gmail.com>
	contact me at https://weibo.com/5632002270/profile
	or http://www.canftin.com
	MIT licence
*/

#pragma once

#include "Math.h"

template <typename T>
class Vec2
{
public:
	T x, y;

public:
	Vec2() {}
	Vec2(T x, T y) : x(x), y(y) {}
	Vec2(const Vec2& vec) : Vec2(vec.x, vec.y) {}
	~Vec2() {}

	template <typename T2>
	explicit operator Vec2<T2>() const
	{
		return { static_cast<T2>(x), static_cast<T2>(y) };
	}

	T LenSquare() const
	{
		return square(*this);
	}
	T		Len() const
	{
		return sqrt(LenSq());
	}
	Vec2&	Normalize()
	{
		const T length = Len();
		x /= length;
		y /= length;
		return *this;
	}
	Vec2	GetNormalized() const
	{
		Vec2 norm = *this;
		norm.Normalize();
		return norm;
	}
	Vec2	operator-() const
	{
		return Vec2(-x, -y);
	}
	Vec2&	operator=(const Vec2 &rhs)
	{
		x = rhs.x;
		y = rhs.y;
		return *this;
	}
	Vec2&	operator+=(const Vec2 &rhs)
	{
		x += rhs.x;
		y += rhs.y;
		return *this;
	}
	Vec2&	operator-=(const Vec2 &rhs)
	{
		x -= rhs.x;
		y -= rhs.y;
		return *this;
	}
	T		operator*(const Vec2 &rhs) const
	{
		return x * rhs.x + y * rhs.y;
	}
	Vec2	operator+(const Vec2 &rhs) const
	{
		return Vec2(*this) += rhs;
	}
	Vec2	operator-(const Vec2 &rhs) const
	{
		return Vec2(*this) -= rhs;
	}
	Vec2&	operator*=(const T &rhs)
	{
		x *= rhs;
		y *= rhs;
		return *this;
	}
	Vec2	operator*(const T &rhs) const
	{
		return Vec2(*this) *= rhs;
	}
	Vec2&	operator/=(const T &rhs)
	{
		x /= rhs;
		y /= rhs;
		return *this;
	}
	Vec2	operator/(const T &rhs) const
	{
		return Vec2(*this) /= rhs;
	}
	bool	operator==(const Vec2 &rhs) const
	{
		return x == rhs.x && y == rhs.y;
	}
	bool	operator!=(const Vec2 &rhs) const
	{
		return !(*this == rhs);
	}
};

using Vector2 = Vec2<float>;
using Vector2i = Vec2<int>;
using Vector2d = Vec2<double>;

