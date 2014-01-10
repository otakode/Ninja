#include "Circle.h"

Circle::Circle() : Body(Shape::CIRCLE)
{
}

Circle::Circle(Type type) : Body(Shape::CIRCLE, type)
{
}

Circle::~Circle()
{
}