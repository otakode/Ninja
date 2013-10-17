#ifndef __VECTOR2_H__
#define __VECTOR2_H__

class Vector2;

//#include <SDL.h>

class Vector2
{
public:
	float x;
	float y;

public:
	Vector2(float X = 0, float Y = 0);
	virtual ~Vector2();

}; // Vector2

#endif // __VECTOR2_H__