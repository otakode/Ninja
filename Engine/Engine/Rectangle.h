#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__

#include "Vector2.h"

struct Rectangle
{
public:
	Vector2<float>	position;
	Vector2<float>	dimension;
	Vector2<float>	orientation;

public:
	float&	width;
	float&	height;

public:
	Rectangle();
	virtual ~Rectangle();

	inline float Width() { return this->top_right.x - this->top_left.x; }
	inline float Height() { return this->top_left.y - this->bottom_left.y; }
}; // Rectangle

#endif // __RECTANGLE_H__