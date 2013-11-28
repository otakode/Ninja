#ifndef __PLAYERCONTROLLER_H__
#define __PLAYERCONTROLLER_H__

class PlayerController;

#include "../../Engine/Engine/Controller.h"
#include "../../Engine/Engine/Entity.h"

class PlayerController : public Controller
{
public:
	PlayerController();
	virtual ~PlayerController();

	virtual void HandleInput(SDLKey key);
}; // PlayerController

#endif // __PLAYERCONTROLLER_H__