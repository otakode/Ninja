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
		DYANAMIC,
		CUSTOM
	};
	enum Shape
	{
		RECTANGLE,
		CIRCLE,
		PIXELMASK
	};

private:
	Type __type;

protected:
	Shape _shape;

public:
	const Type& type;
	const Shape& shape;

public:
	Body(Shape shape, Type type = Type::DYANAMIC);
	virtual ~Body();

	bool Collide(Body& other);

protected:

	static bool Collide_Rectangle(Body* a, Body* b);
	static bool Collide_Circle(Body* a, Body* b);
	static bool Collide_PixelMask(Body* a, Body* b);

	static bool Collide_Rectangle_Rectangle(Body* a, Body* b);
	static bool Collide_Rectangle_Circle(Body* a, Body* b);
	static bool Collide_Rectangle_PixelMask(Body* a, Body* b);

	static bool Collide_Circle_Rectangle(Body* a, Body* b);
	static bool Collide_Circle_Circle(Body* a, Body* b);
	static bool Collide_Circle_PixelMask(Body* a, Body* b);

	static bool Collide_PixelMask_Rectangle(Body* a, Body* b);
	static bool Collide_PixelMask_Circle(Body* a, Body* b);
	static bool Collide_PixelMask_PixelMask(Body* a, Body* b);
}; // Body

#endif // __BODY_H__