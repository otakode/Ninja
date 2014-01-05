#ifndef __PHYSICSMANAGER_H__
#define __PHYSICSMANAGER_H__

class PhysicsManager;

#include "Manager.h"
#include "Body.h"

class PhysicsManager : public Manager
{
protected:
	std::list<Body*> _registry;

public:
	PhysicsManager();
	virtual ~PhysicsManager();

	void Register(Body* body);
	void UnRegister(Body* body);

	virtual bool Routine();

}; // PhysicsManager

#endif // __PHYSICSMANAGER_H__