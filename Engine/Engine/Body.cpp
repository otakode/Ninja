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
			return Collide_Rectangle(this, &other);
		case Body::Shape::CIRCLE:
			return Collide_Circle(this, &other);
		default: //case Body::Shape::PIXELMASK:
			return Collide_PixelMask(this, &other);
	}
}


bool Body::Collide_Rectangle(Body* a, Body* b)
{
	switch (b->shape)
	{
		case Body::Shape::RECTANGLE:
			return Collide_Rectangle_Rectangle(a, b);
		case Body::Shape::CIRCLE:
			return Collide_Rectangle_Circle(a, b);
		default: //case Body::Shape::PIXELMASK:
			return Collide_Rectangle_PixelMask(a, b);
	}
}

bool Body::Collide_Circle(Body* a, Body* b)
{
	switch (b->shape)
	{
		case Body::Shape::RECTANGLE:
			return Collide_Circle_Rectangle(a, b);
		case Body::Shape::CIRCLE:
			return Collide_Circle_Circle(a, b);
		default: //case Body::Shape::PIXELMASK:
			return Collide_Circle_PixelMask(a, b);
	}
}

bool Body::Collide_PixelMask(Body* a, Body* b)
{
	switch (b->shape)
	{
		case Body::Shape::RECTANGLE:
			return Collide_PixelMask_Rectangle(a, b);
		case Body::Shape::CIRCLE:
			return Collide_PixelMask_Circle(a, b);
		default: //case Body::Shape::PIXELMASK:
			return Collide_PixelMask_PixelMask(a, b);
	}
}


bool Body::Collide_Rectangle_Rectangle(Body* a, Body* b)
{
	return false;
}

bool Body::Collide_Rectangle_Circle(Body* a, Body* b)
{
	return false;
}

bool Body::Collide_Rectangle_PixelMask(Body* a, Body* b)
{
	return false;
}


bool Body::Collide_Circle_Rectangle(Body* a, Body* b)
{
	return false;
}

bool Body::Collide_Circle_Circle(Body* a, Body* b)
{
	return false;
}

bool Body::Collide_Circle_PixelMask(Body* a, Body* b)
{
	return false;
}


bool Body::Collide_PixelMask_Rectangle(Body* a, Body* b)
{
	return false;
}

bool Body::Collide_PixelMask_Circle(Body* a, Body* b)
{
	return false;
}

bool Body::Collide_PixelMask_PixelMask(Body* a, Body* b)
{
	return false;
}