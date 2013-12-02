#include "Body.h"
#include "Game.h"

Body::Body(Type type, Shape shape) : Component(Component::Type::BODY), __type(type), _shape(shape), type(__type), shape(_shape)
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
	return false;
}