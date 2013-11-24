#ifndef __GAME_H__
#define __GAME_H__

class Game;

#include "GraphicsManager.h"
#include "ControlsManager.h"
#include "SoundsManager.h"
#include "PhysicsManager.h"
#include "Level.h"

class Game
{
private:
	static Game* _instance;
	bool running = false;

public:
	ControlsManager* controls;
	PhysicsManager* physics;
	SoundsManager* sounds;
	GraphicsManager* graphics;
	Level* level;

public:
	Game();
	virtual ~Game();

	virtual bool Init();
	void Run();

	static void Quit();
	static ControlsManager* GetControlsManager();
	static PhysicsManager* GetPhysicsManager();
	static SoundsManager* GetSoundsManager();
	static GraphicsManager* GetGraphicsManager();
	static void LoadLevel(Level* level);
	static Level* GetCurrentLevel();

}; // Game

#endif // __GAME_H__