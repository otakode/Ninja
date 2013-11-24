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
		if (e.type == SDL_KEYDOWN)
		{
			for (std::multimap<SDLKey, Controller*>::iterator it = this->_registry.find(e.key.keysym.sym); it->first == e.key.keysym.sym; ++it)
			{
				it->second->HandleInput(e.key.keysym.sym);
			}
		}
	}

	return true;
}

void ControlsManager::RegisterToKey(Controller* controller, SDLKey key)
{
	this->_registry.emplace(key, controller);
}

void ControlsManager::UnRegisterToKey(Controller* controller, SDLKey key)
{
	for (std::multimap<SDLKey, Controller*>::iterator it = this->_registry.find(key); it->first == key; ++it)
	{
		if (it->second == controller)
		{
			this->_registry.erase(it);
		}
	}
}