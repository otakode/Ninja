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
	// brute force
	for (std::list<Body*>::iterator a = this->_registry.begin(), a_end = this->_registry.end(); a != a_end; ++a)
	{
		for (std::list<Body*>::iterator b = a, b_end = this->_registry.end(); ++b != b_end; )
		{
			(*a)->Collide(*(*b));
		}
	}
	return true;
}