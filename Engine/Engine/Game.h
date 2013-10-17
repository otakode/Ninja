#ifndef __GAME_H__
#define __GAME_H__

class Game;

#include <list>
#include "Level.h"
#include "GraphicsManager.h"
#include "ControlsManager.h"
#include "SoundsManager.h"
#include "PhysicsManager.h"

class Game
{
	std::list<Level> levels;
	GraphicsManager graphics;
	ControlsManager controls;
	SoundsManager sounds;
	PhysicsManager physics;

public:
	Game();
	virtual ~Game();
}; // Game

#endif // __GAME_H__