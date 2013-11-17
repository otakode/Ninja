#ifndef __MANAGER_H__
#define __MANAGER_H__

class Manager;

#include <list>
#include "Component.h"

class Manager
{
private:
	Component::Type validComponent;

protected:
	std::list<Component*> _registry;

public:
	Manager(Component::Type type);
	virtual ~Manager();

	void Register(Component* c);
	void UnRegister(Component* c);

	bool ValidComponent(Component::Type type);

	virtual bool Routine();
}; // Manager

#endif // __GRAPHICSMANAGER_H__