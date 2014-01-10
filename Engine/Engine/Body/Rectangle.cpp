#include "Rectangle.h"

Rectangle::Rectangle() : Body(Shape::RECTANGLE)
{
}

Rectangle::Rectangle(Type type) : Body(Shape::RECTANGLE, type)
{
}

Rectangle::~Rectangle()
{
}