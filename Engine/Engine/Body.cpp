#include "Body.h"
#include "Game.h"
#include "Body/Rectangle.h"
#include "Body/Circle.h"
#include "Body/PixelMask.h"

Body::Body(Shape shape, Type type) : Component(Component::Type::BODY), __type(type), _shape(shape), type(__type), shape(_shape)
{
	PhysicsManager* manager = Game::GetPhysicsManager();
	if (manager != NULL)
	{
		manager->Register(this);
	}
}

Body::~Body()
{
	PhysicsManager* manager = Game::GetPhysicsManager();
	if (manager != NULL)
	{
		manager->UnRegister(this);
	}
}

bool Body::Collide(Body& other)
{
	switch (this->shape)
	{
		case Body::Shape::RECTANGLE:
			return Collide_Rectangle((Rectangle*)this, &other);
		case Body::Shape::CIRCLE:
			return Collide_Circle((Circle*)this, &other);
		default: //case Body::Shape::PIXELMASK:
			return Collide_PixelMask((PixelMask*)this, &other);
	}
}


bool Body::Collide_Rectangle(Rectangle* a, Body* b)
{
	switch (b->shape)
	{
		case Body::Shape::RECTANGLE:
			return Collide_Rectangle_Rectangle(a, (Rectangle*)b);
		case Body::Shape::CIRCLE:
			return Collide_Rectangle_Circle(a, (Circle*)b);
		default: //case Body::Shape::PIXELMASK:
			return Collide_Rectangle_PixelMask(a, (PixelMask*)b);
	}
}

bool Body::Collide_Circle(Circle* a, Body* b)
{
	switch (b->shape)
	{
		case Body::Shape::RECTANGLE:
			return Collide_Circle_Rectangle(a, (Rectangle*)b);
		case Body::Shape::CIRCLE:
			return Collide_Circle_Circle(a, (Circle*)b);
		default: //case Body::Shape::PIXELMASK:
			return Collide_Circle_PixelMask(a, (PixelMask*)b);
	}
}

bool Body::Collide_PixelMask(PixelMask* a, Body* b)
{
	switch (b->shape)
	{
		case Body::Shape::RECTANGLE:
			return Collide_PixelMask_Rectangle(a, (Rectangle*)b);
		case Body::Shape::CIRCLE:
			return Collide_PixelMask_Circle(a, (Circle*)b);
		default: //case Body::Shape::PIXELMASK:
			return Collide_PixelMask_PixelMask(a, (PixelMask*)b);
	}
}


bool Body::Collide_Rectangle_Rectangle(Rectangle* a, Rectangle* b)
{
	return false;
}

bool Body::Collide_Rectangle_Circle(Rectangle* a, Circle* b)
{
	return false;
}

bool Body::Collide_Rectangle_PixelMask(Rectangle* a, PixelMask* b)
{
	return false;
}


bool Body::Collide_Circle_Rectangle(Circle* a, Rectangle* b)
{
	return false;
}

bool Body::Collide_Circle_Circle(Circle* a, Circle* b)
{
	return false;
}

bool Body::Collide_Circle_PixelMask(Circle* a, PixelMask* b)
{
	return false;
}


bool Body::Collide_PixelMask_Rectangle(PixelMask* a, Rectangle* b)
{
	return false;
}

bool Body::Collide_PixelMask_Circle(PixelMask* a, Circle* b)
{
	return false;
}

bool Body::Collide_PixelMask_PixelMask(PixelMask* a, PixelMask* b)
{
	return false;
}