#include "Entity.h"

Entity::Entity(Entity* parent, float x, float y) : /*parent(_parent),*/ pos(_pos), children(_children), components(_components), _pos(0, 0)
{
	this->_parent = parent;
	this->_pos.x = x;
	this->_pos.y = y;
}

Entity::Entity(Entity& model) : /*parent(_parent),*/ pos(_pos), children(_children), components(_components), _pos(0, 0)
{
	this->_parent = model._parent;
	this->_pos = model.pos;
	this->_children = model.children;
	this->_components = model.components;
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
	if (this->_parent != NULL)
		this->_parent->DelChild(this);
}

Vector2<> Entity::GetAbsolutePos()
{
	Vector2<> absPos = this->pos;

	Entity* entity = this;
	while (entity->_parent != NULL)
	{
		entity = entity->_parent;
		absPos.x += entity->pos.x;
		absPos.y += entity->pos.y;
	}
	return absPos;
}

void Entity::AddChild(int offset, Entity* child)
{
	this->_children.insert(std::pair<int, Entity*>(offset, child));
	child->_parent = this;
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
	this->_components.insert(std::pair<Component::Type, Component*>(component->type, component));
}

void Entity::DelComponent(Component* component)
{
	this->_components.erase(this->_components.find(component->type));
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