#include <stdafx.h>
#include "Entity.h"

Entity::Entity(Entity* parent, int x, int y) : parent(_parent), pos(_pos), children(_children)//, components(_components)
{
	this->_pos.x = x;
	this->_pos.y = y;
}

Entity::Entity(Entity& model) : parent(_parent), pos(_pos), children(_children)//, components(_components)
{
	this->_parent = model.parent;
	this->_pos = model.pos;
	this->_children = model.children;
//	this->_components = model.components;
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
	this->parent->DelChild(this);
}

void	Entity::AddChild(int offset, Entity* child)
{
	this->_children.insert(std::pair<int, Entity*>(offset, child));
}

void	Entity::DelChild(Entity* child)
{
//	this->_children.insert(std::pair<int, Entity*>(offset, child));
}
