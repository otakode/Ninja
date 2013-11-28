#include "Player.h"
#include "../../Engine/Engine/Graphic.h"
#include "PlayerController.h"

Player::Player()
{
	this->AddComponent(new Graphic(80, 20, 0xFFFFFFFF));
	this->AddComponent(new PlayerController());
}

Player::~Player()
{
}
