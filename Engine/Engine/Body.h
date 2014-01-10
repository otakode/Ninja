#ifndef __BODY_H__
#define __BODY_H__

#include "Component.h"
#include "Vector2.h"

class Rectangle;
class Circle;
class PixelMask;

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

	static bool Collide_Rectangle(Rectangle* a, Body* b);
	static bool Collide_Circle(Circle* a, Body* b);
	static bool Collide_PixelMask(PixelMask* a, Body* b);

	static bool Collide_Rectangle_Rectangle(Rectangle* a, Rectangle* b);
	static bool Collide_Rectangle_Circle(Rectangle* a, Circle* b);
	static bool Collide_Rectangle_PixelMask(Rectangle* a, PixelMask* b);

	static bool Collide_Circle_Rectangle(Circle* a, Rectangle* b);
	static bool Collide_Circle_Circle(Circle* a, Circle* b);
	static bool Collide_Circle_PixelMask(Circle* a, PixelMask* b);

	static bool Collide_PixelMask_Rectangle(PixelMask* a, Rectangle* b);
	static bool Collide_PixelMask_Circle(PixelMask* a, Circle* b);
	static bool Collide_PixelMask_PixelMask(PixelMask* a, PixelMask* b);
}; // Body

#endif // __BODY_H__