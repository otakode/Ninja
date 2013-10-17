#include "Component.h"

Component::Component(Type type) : type(_type)
{
	this->_type = type;
}

Component::~Component()
{
}
