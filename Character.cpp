#include "Character.h"

Character::Character() : Surface(100, 100, 0xFF0000)
{
	this->_speed = 10;
	this->_dir = 0;
	this->_jumping = -10;
}

Character::~Character()
{
}

void	Character::Move(int dir)
{
	this->_dir = dir;
}

void	Character::Jump()
{
	if (this->_jumping == -10)
		this->_jumping = 9;
}

void	Character::Update()
{
	this->rect.x += this->_speed * this->_dir;
	if (this->_jumping != -10)
	{
		this->rect.y -= this->_jumping;
		this->_jumping -= 1;
	}
}