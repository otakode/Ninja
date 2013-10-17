#include "SoundsManager.h"

SoundsManager::SoundsManager()
{
}

SoundsManager::~SoundsManager()
{
}

bool SoundsManager::validComponent(Component::Type type)
{
	return (type == Component::Type::SOUND ? true : false);
}