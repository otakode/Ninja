#include "GraphicsManager.h"

GraphicsManager::GraphicsManager()
{
}

GraphicsManager::~GraphicsManager()
{
}

bool GraphicsManager::validComponent(Component::Type type)
{
	return (type == Component::Type::GRAPHIC ? true : false);
}