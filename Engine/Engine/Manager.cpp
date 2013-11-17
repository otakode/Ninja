#include "Manager.h"

Manager::Manager(Component::Type type) : validComponent(type)
{
}

Manager::~Manager()
{
}

void Manager::Register(Component* c)
{
	if (this->ValidComponent(c->type))
		this->_registry.push_back(c);
}

void Manager::UnRegister(Component* c)
{
	this->_registry.remove(c);
}

bool Manager::ValidComponent(Component::Type type)
{
	return (type == validComponent);
}

bool Manager::Routine()
{
	return true;
}