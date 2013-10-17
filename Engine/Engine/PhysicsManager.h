#ifndef __PHYSICSMANAGER_H__
#define __PHYSICSMANAGER_H__

class PhysicsManager;

#include "Manager.h"

class PhysicsManager : public Manager
{
public:
	PhysicsManager();
	virtual ~PhysicsManager();

	virtual bool validComponent(Component::Type type);
}; // PhysicsManager

#endif // __PHYSICSMANAGER_H__