#include "ControlsManager.h"
#include <SDL/SDL.h>

ControlsManager::ControlsManager() : Manager(Component::CONTROLLER)
{
}

ControlsManager::~ControlsManager()
{
}

bool ControlsManager::Routine()
{
	SDL_Event e;
	if (SDL_PollEvent(&e))
	{
		if (e.type == SDL_QUIT)
			return false;
	}

	return true;
}