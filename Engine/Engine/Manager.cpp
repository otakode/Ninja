#include "Manager.h"

Manager::Manager()
{
}

Manager::~Manager()
{
}

void Manager::Register(Component* c)
{
	if (validComponent(c->type))
		this->_registry.push_back(c);
}

void Manager::UnRegister(Component* c)
{
	this->_registry.remove(c);
}

bool Manager::validComponent(Component::Type type)
{
	return true;
}