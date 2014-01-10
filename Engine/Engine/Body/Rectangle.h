#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__

#include "../Body.h"

class Rectangle : public Body
{
public:
	Rectangle();
	Rectangle(Type type);
	virtual ~Rectangle();

}; // Rectangle

#endif // __RECTANGLE_H__