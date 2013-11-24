#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

class Controller;

#include "Component.h"
#include <SDL/SDL.h>

class Controller : public Component
{
public:
	Controller();
	virtual ~Controller();

	virtual void HandleInput(SDLKey input);
}; // Controller

#endif // __CONTROLLER_H__