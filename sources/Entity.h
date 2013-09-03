#ifndef __ENTITY_H__
#define __ENTITY_H__

#include <map>
#include <SDL.h>

class Entity
{
protected:
	Entity*												_parent;
	SDL_Rect											_pos;
	std::multimap<int, Entity*>							_children;
	//std::multimap<COMPONENT_TYPE type, Component*>	_components;

public:
	Entity*& const											parent;
	const SDL_Rect&											pos;
	const std::multimap<int, Entity*>&						children;
	//const std::multimap<COMPONENT_TYPE type, Component*>&	components;

public:
	Entity(Entity* parent, int x = 0, int y = 0);
	Entity(Entity& model);
	virtual ~Entity();

	void	AddChild(int offset, Entity* child);
	void	DelChild(Entity* child);
//	void	AddComponent(Component* component);
//	void	DelComponent(Component* component);
//	std::array<Component*>	GetComponent(COMPONENT_TYPE);
};

#endif // __ENTITY_H__