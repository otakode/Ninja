#ifndef __MANAGER_H__
#define __MANAGER_H__

class Manager;

#include <list>
#include "Component.h"

class Manager
{
private:
	Component::Type validComponent;

public:
	Manager(Component::Type type);
	virtual ~Manager();

	bool ValidComponent(Component::Type type);

	virtual bool Routine();
}; // Manager

#endif // __GRAPHICSMANAGER_H__