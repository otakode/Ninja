#include "stdafx.h"
#include "Character.h"

Character::Character() : Surface(100, 100, 0xFF0000)
{
	this->_speed = 10.0f;
	this->_dir = 0.0f;
	this->_jumping = -10.0f;
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
	if (this->_jumping <= -10.0f)
		this->_jumping = 9.0f;
}

void	Character::Update()
{
	float	elapsed = this->_time.Elapsed();
	this->rect.x += (int)(elapsed * this->_speed * this->_dir);
	if (this->_jumping > -10.0f)
	{
		this->rect.y -= (int)(elapsed * this->_jumping);
		this->_jumping -= 1.0f;
	}
}