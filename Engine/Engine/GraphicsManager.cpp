#include "GraphicsManager.h"

GraphicsManager::GraphicsManager() : screen(_screen), _screen(800, 600)
{
}

GraphicsManager::~GraphicsManager()
{
}

bool GraphicsManager::validComponent(Component::Type type)
{
	return (type == Component::Type::GRAPHIC ? true : false);
}