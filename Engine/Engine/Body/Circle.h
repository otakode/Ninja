#ifndef __CIRCLE_H__
#define __CIRCLE_H__

#include "../Body.h"

class Circle : public Body
{
public:
	Circle();
	Circle(Type type);
	virtual ~Circle();

}; // Circle

#endif // __CIRCLE_H__