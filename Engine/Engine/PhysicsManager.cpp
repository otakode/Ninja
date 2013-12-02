#include "PhysicsManager.h"

PhysicsManager::PhysicsManager() : Manager(Component::BODY)
{
}

PhysicsManager::~PhysicsManager()
{
}

void PhysicsManager::Register(Body* body)
{
	this->_registry.push_back(body);
}

void PhysicsManager::UnRegister(Body* body)
{
	this->_registry.remove(body);
}

bool PhysicsManager::Routine()
{
	return true;
}