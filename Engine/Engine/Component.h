#ifndef __COMPONENT_H__
#define __COMPONENT_H__

class Entity;

class Component
{
public:
	enum Type
	{
		NONE,
		GRAPHIC,
		CONTROLLER,
		BODY,
		SOUND
	};

protected:
	Type _type;

public:
	const Type& type;
	Entity* entity;

public:
	Component(Type type = Component::Type::NONE);
	virtual ~Component();

}; // Component

#endif // __COMPONENT_H__