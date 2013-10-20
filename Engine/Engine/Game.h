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
private:
	static Game* _instance;
	static std::list<Level> _levels;
	static GraphicsManager _graphics;
	static ControlsManager _controls;
	static SoundsManager _sounds;
	static PhysicsManager _physics;

public:
	static const std::list<Level>& levels;
	static GraphicsManager& graphics;
	static ControlsManager& controls;
	static SoundsManager& sounds;
	static PhysicsManager& physics;

protected:
	Game();
	virtual ~Game();

public:
	static void Run();

}; // Game

#endif // __GAME_H__