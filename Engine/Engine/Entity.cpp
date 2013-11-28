#include "Entity.h"

Entity::Entity() : /*parent(_parent), pos(_pos),*/ children(_children), components(_components), parent(NULL), pos(0, 0)
{
}

Entity::Entity(Entity& model) : /*parent(_parent), pos(_pos),*/ children(_children), components(_components), parent(NULL), pos(0, 0)
{
	// make copy of components & children;
}

Entity::~Entity()
{
	while (!this->_components.empty())
	{
		delete this->_components.begin()->second;
		this->_components.erase(this->_components.begin());
	}
	while (!this->_children.empty())
	{
		delete this->_children.begin()->second;
//		this->_children.erase(this->_children.begin());
	}
/*	for (std::multimap<int, Entity*>::iterator it = this->children.begin(), e = this->children.end(); it != e; ++it)
	{
		delete it->second; // crash, because of array modification
	}*/
	if (this->parent != NULL)
		this->parent->DelChild(this);
}

Vector2<> Entity::GetAbsolutePos()
{
	Vector2<> absPos = this->pos;

	Entity* entity = this;
	while (entity->parent != NULL)
	{
		entity = entity->parent;
		absPos.x += entity->pos.x;
		absPos.y += entity->pos.y;
	}
	return absPos;
}

void Entity::AddChild(Entity* child, int offset, Vector2<> pos)
{
	this->_children.emplace(offset, child);
	child->parent = this;
	child->pos = pos;
}

void Entity::DelChild(Entity* child)
{
	for (std::multimap<int, Entity*>::iterator it = this->_children.begin(), e = this->_children.end(); it != e; ++it)
	{
		if (it->second == child)
		{
			this->_children.erase(it);
			break;
		}
	}
}

std::vector<Entity*> Entity::GetChildWithComponent(Component::Type type)
{
	std::vector<Entity*> list;

	if (this->GetComponent(type) != NULL)
		list.push_back(this);
	for (std::multimap<int, Entity*>::iterator it = this->_children.begin(), e = this->_children.end(); it != e; it++)
	{
		std::vector<Entity*> sublist = it->second->GetChildWithComponent(type);
		if (!sublist.empty())
			list.insert(list.end(), sublist.begin(), sublist.end());
	}
	return list;
}

void Entity::AddComponent(Component* component)
{
	this->_components.emplace(component->type, component);
	component->entity = this;
}

void Entity::DelComponent(Component* component)
{
	this->_components.erase(this->_components.find(component->type));
	component->entity = NULL;
}

Component* Entity::GetComponent(Component::Type type)
{
	if (this->_components.find(type) != this->_components.end())
		return this->_components.find(type)->second;
	return NULL;
}

std::vector<Component*> Entity::GetComponentsRecursive(Component::Type type)
{
	std::vector<Component*> list;

	if (this->GetComponent(type) != NULL)
		list.push_back(this->_components[type]);
	for (std::multimap<int, Entity*>::iterator it = this->_children.begin(), e = this->_children.end(); it != e; it++)
	{
		std::vector<Component*> sublist = it->second->GetComponentsRecursive(type);
		if (!sublist.empty())
			list.insert(list.end(), sublist.begin(), sublist.end());
	}
	return list;
}