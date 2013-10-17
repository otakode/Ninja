#ifndef __COMPONENT_H__
#define __COMPONENT_H__

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
	Type	_type;

public:
	const Type&	type;

public:
	Component(Type type);
	virtual ~Component();


}; // Component

#endif // __COMPONENT_H__