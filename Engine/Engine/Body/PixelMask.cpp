#include "PixelMask.h"

PixelMask::PixelMask() : Body(Shape::PIXELMASK)
{
}

PixelMask::PixelMask(Type type) : Body(Shape::PIXELMASK, type)
{
}

PixelMask::~PixelMask()
{
}