#include "stdafx.h"
#include "Character.h"

Character::Character() : Surface(100, 100, 0xFF0000)
{
	this->_speed = 30.0f;
	this->_dir = 0.0f;
	this->_jumping = -1.0f;
	this->x = (float)this->pos.x;
	this->y = (float)this->pos.y;
}

Character::~Character()
{
}

void	Character::Move(float dir)
{
	this->_dir = dir;
}

void	Character::Jump()
{
	if (this->_jumping <= -1.0f)
		this->_jumping = 1.0f;
}

void	Character::Update()
{
	float	elapsed = Time::elapsed;
	this->x += elapsed * this->_speed * this->_dir;
/*	if (this->_jumping > -1.0f)
	{
		this->y -= elapsed * this->_speed * this->_jumping;
		this->_jumping -= elapsed;
	}*/
	this->pos.x = (int)this->x;
	this->pos.y = (int)this->y;
}