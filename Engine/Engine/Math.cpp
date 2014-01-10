#include "Math.h"
#include <cmath>

Math::Math()
{
}

Math::~Math()
{
}

float Math::Distance(Vector2<float> a, Vector2<float> b)
{
	return (sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2)));
}