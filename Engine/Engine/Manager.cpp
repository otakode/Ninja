#include "Manager.h"

Manager::Manager(Component::Type type) : validComponent(type)
{
}

Manager::~Manager()
{
}

bool Manager::ValidComponent(Component::Type type)
{
	return (type == validComponent);
}

bool Manager::Routine()
{
	return true;
}