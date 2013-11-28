#include "PlayerController.h"
#include "../../Engine/Engine/Time.h"
#include "../../Engine/Engine/Game.h"

PlayerController::PlayerController()
{
	Game::GetControlsManager()->RegisterToKey(this, SDLK_RIGHT);
	Game::GetControlsManager()->RegisterToKey(this, SDLK_LEFT);
}

PlayerController::~PlayerController()
{
}

void PlayerController::HandleInput(SDLKey key)
{
	switch (key)
	{
		case SDLK_RIGHT:
			this->entity->pos.x += Time::elapsed * 200;
			break;
		case SDLK_LEFT:
			this->entity->pos.x -= Time::elapsed * 200;
			break;
		default:
			break;
	}
}