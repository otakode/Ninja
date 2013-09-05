#include <stdafx.h>
#include "Entity.h"

Entity::Entity(Entity* parent, int x, int y) : parent(_parent), pos(_pos), children(_children), components(_components)
{
	this->_parent = parent;
	this->_pos.x = x;
	this->_pos.y = y;
}

Entity::Entity(Entity& model) : parent(_parent), pos(_pos), children(_children), components(_components)
{
	this->_parent = model.parent;
	this->_pos = model.pos;
	this->_children = model.children;
	this->_components = model.components;
}

Entity::~Entity()
{
	while (!this->children.empty())
	{
		delete this->children.begin()->second;
	}
/*	for (std::multimap<int, Entity*>::iterator it = this->children.begin(), e = this->children.end(); it != e; ++it)
	{
		delete it->second; // crash, because of array modification
	}*/
	if (this->parent != NULL)
		this->parent->DelChild(this);
}

void	Entity::AddChild(int offset, Entity* child)
{
	this->_children.insert(std::pair<int, Entity*>(offset, child));
	child->_parent = this;
}

void	Entity::DelChild(Entity* child)
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

void	Entity::AddComponent(Component* component)
{
	this->_components.insert(std::pair<Component::Type, Component*>(component->type, component));
}

void	Entity::DelComponent(Component* component)
{
	this->_components.erase(this->_components.find(component->type));
}