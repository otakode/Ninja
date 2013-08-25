#include "Character.h"

Character::Character() : Surface(100, 100, 0xFF0000)
{
	this->_speed = 10;
	this->_dir = 0;
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
}

void	Character::Update()
{
	this->rect.x += this->_speed * this->_dir;
}