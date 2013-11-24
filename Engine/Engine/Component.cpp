#include "Component.h"
#include "Entity.h"

Component::Component(Component::Type type) : type(_type), _type(type)
{
}

Component::~Component()
{
}
