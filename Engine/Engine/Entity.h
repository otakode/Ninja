#ifndef __ENTITY_H__
#define __ENTITY_H__

#include <map>
#include <vector>
//#include <SDL.h>
#include "Vector2.h"
#include "Component.h"

class Entity
{
protected:
//	Entity* _parent;
//	Vector2<> _pos;
	std::multimap<int, Entity*> _children;
	std::map<Component::Type, Component*> _components;

public:
	Entity* parent;
	Vector2<> pos;
	const std::multimap<int, Entity*>& children;
	const std::map<Component::Type, Component*>& components;

public:
	Entity();
	Entity(Entity& model);
	virtual ~Entity();

	Vector2<> GetAbsolutePos();

	void AddChild(Entity* child, int offset, Vector2<> pos);
	void DelChild(Entity* child);
	std::vector<Entity*> GetChildWithComponent(Component::Type type);

	void AddComponent(Component* component);
	void DelComponent(Component* component);
	Component* GetComponent(Component::Type type);
	std::vector<Component*> GetComponentsRecursive(Component::Type type);
}; // Entity

#endif // __ENTITY_H__