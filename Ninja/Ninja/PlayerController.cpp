#include "PlayerController.h"
#include "../../Engine/Engine/Time.h"

PlayerController::PlayerController()
{
}

PlayerController::~PlayerController()
{
}

void PlayerController::HandleInput(SDLKey key)
{
	switch (key)
	{
		case SDLK_RIGHT:
			this->entity->pos.x += Time::elapsed * 50;
			break;
		case SDLK_LEFT:
			this->entity->pos.x -= Time::elapsed * 50;
			break;
		default:
			break;
	}
}