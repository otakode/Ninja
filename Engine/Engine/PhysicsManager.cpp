#include "PhysicsManager.h"

PhysicsManager::PhysicsManager()
{
}

PhysicsManager::~PhysicsManager()
{
}

bool PhysicsManager::validComponent(Component::Type type)
{
	return (type == Component::Type::BODY ? true : false);
}