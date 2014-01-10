#ifndef __MATH_H__
#define __MATH_H__

#include "Vector2.h"

class Math
{
public:
	Math();
	virtual ~Math();

	inline static float Distance(Vector2<float>a, Vector2<float>b);
	
}; // Math

#endif // __MATH_H__