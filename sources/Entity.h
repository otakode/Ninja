#ifndef __ENTITY_H__
#define __ENTITY_H__

#include <map>
#include <vector>
#include <SDL.h>

#include "Component.h"

class Entity
{
protected:
	Entity*									_parent;
	SDL_Rect								_pos;
	std::multimap<int, Entity*>				_children;
	std::map<Component::Type, Component*>	_components;

public:
	Entity*& 										parent;
	SDL_Rect&										pos;
	const std::multimap<int, Entity*>&				children;
	const std::map<Component::Type, Component*>&	components;

public:
	Entity(Entity* parent = NULL, int x = 0, int y = 0);
	Entity(Entity& model);
	virtual ~Entity();

	SDL_Rect	GetAbsolutePos();

	void	AddChild(int offset, Entity* child);
	void	DelChild(Entity* child);
	std::vector<Entity*>	GetChildWithComponent(Component::Type type);

	void	AddComponent(Component* component);
	void	DelComponent(Component* component);
	Component*	GetComponent(Component::Type type);
	std::vector<Component*>	GetComponentsRecursive(Component::Type type);
}; // Entity

#endif // __ENTITY_H__