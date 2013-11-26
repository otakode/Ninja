#include "ControlsManager.h"
#include <SDL/SDL.h>

ControlsManager::ControlsManager() : Manager(Component::CONTROLLER)
{
//	this->_keys = SDL_GetKeyState(NULL);
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
/*		if (e.type == SDL_KEYDOWN) // instant events
		{
			for (std::multimap<SDLKey, Controller*>::iterator it = this->_registry.find(e.key.keysym.sym); it != this->_registry.end() && it->first == e.key.keysym.sym; ++it)
			{
				it->second->HandleInput(it->first);
			}
		}*/
	}
	this->_keys = SDL_GetKeyState(NULL);
	for (std::multimap<SDLKey, Controller*>::iterator it = this->_registry.begin(), e = this->_registry.end(); it != e; ++it)
	{
		if (this->_keys[it->first])
			it->second->HandleInput(it->first);
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