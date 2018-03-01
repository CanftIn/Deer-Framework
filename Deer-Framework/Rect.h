/*
	Copyright (c) 2018 by CanftIn <wwc7033@gmail.com>
	contact me at https://weibo.com/5632002270/profile
	or http://www.canftin.com
	MIT licence
*/

#pragma once

#include "Vec2.h"
#include <algorithm>

template < typename T >
class Rect
{
public:
	inline	Rect() {}
	inline	Rect(T top, T bottom, T left, T right)
		:
		top(top),
		bottom(bottom),
		left(left),
		right(right)
	{}
	inline	Rect(const Rect& rect)
		:
		top(rect.top),
		bottom(rect.bottom),
		left(rect.left),
		right(rect.right)
	{}
	inline	Rect(Vec2<T> p0, Vec2<T> p1)
		:
		Rect(min(p0.y, p1.y),
			max(p0.y, p1.y),
			min(p0.x, p1.x),
			max(p0.x, p1.x))
	{}
	inline	void Translate(Vec2<T> d)
	{
		Translate(d.x, d.y);
	}
	inline	void Translate(T dx, T dy)
	{
		top += dy;
		bottom += dy;
		left += dx;
		right += dx;
	}
	template <typename T2>
	inline	operator Rect<T2>() const
	{
		return { (T2)top,(T2)bottom,(T2)left,(T2)right };
	}
	inline	void ClipTo(const Rect& rect)
	{
		top = std::max(top, rect.top);
		bottom = std::min(bottom, rect.bottom);
		left = std::max(left, rect.left);
		right = std::min(right, rect.right);
	}
	inline	T GetWidth() const
	{
		return right - left;
	}
	inline	T GetHeight() const
	{
		return bottom - top;
	}
	inline	bool Overlaps(const Rect& rect) const
	{
		return top < rect.bottom && bottom > rect.top &&
			left < rect.right && right > rect.left;
	}
	template <typename T2>
	inline	bool Contains(Vec2<T2> p) const
	{
		return p.y >= top && p.y <= bottom && p.x >= left && p.x <= right;
	}
	template <typename T2>
	inline	bool Contains(Rect<T2> p) const
	{
		return p.top >= top && p.bottom <= bottom && p.left >= left && p.right <= right;
	}
public:
	T top;
	T bottom;
	T left;
	T right;
};

typedef Rect< int > RectI;
typedef Rect< float > RectF;