#include "ControlsManager.h"

ControlsManager::ControlsManager()
{
}

ControlsManager::~ControlsManager()
{
}

bool ControlsManager::validComponent(Component::Type type)
{
	return (type == Component::Type::CONTROLLER ? true : false);
}