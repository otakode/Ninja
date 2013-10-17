#ifndef __MANAGER_H__
#define __MANAGER_H__

class Manager;

#include <list>
#include "Component.h"

class Manager
{
protected:
	std::list<Component*> _registry;

public:
	Manager();
	virtual ~Manager();

	void Register(Component* c);
	void UnRegister(Component* c);

	virtual bool validComponent(Component::Type type);
}; // Manager

#endif // __GRAPHICSMANAGER_H__