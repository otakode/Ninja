#include "Ball.h"
#include "../../Engine/Engine/Graphic.h"

Ball::Ball()
{
	this->AddComponent(new Graphic(20, 20, 0xFFFFFFFF));
}

Ball::~Ball()
{
}
