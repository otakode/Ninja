#ifndef __BODY_H__
#define __BODY_H__

#include "Component.h"
#include "Vector2.h"

class Body : public Component
{
public:
	enum Type
	{
		STATIC,
		DYANAMIC
	};
	enum Shape
	{
		BOX,
		CIRCLE,
		POLYGON
	};

private:
	Type __type;

protected:
	Shape _shape;

public:
	const Type& type;
	const Shape& shape;

public:
	Body(Type type, Shape shape);
	virtual ~Body();

	bool Collide(Body& other);
}; // Body

#endif // __BODY_H__