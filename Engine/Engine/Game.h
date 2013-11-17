#ifndef __GAME_H__
#define __GAME_H__

class Game;

#include "Level.h"
#include "GraphicsManager.h"
#include "ControlsManager.h"
#include "SoundsManager.h"
#include "PhysicsManager.h"

class Game
{
private:
	static Game* _instance;
	bool running = false;

public:
	Level* level;
	ControlsManager* controls;
	PhysicsManager* physics;
	SoundsManager* sounds;
	GraphicsManager* graphics;

public:
	Game();
	virtual ~Game();

	virtual bool Init();
	void Run();

	static void Quit();
	static void LoadLevel(Level* level);
	static Level* GetCurrentLevel();
	static ControlsManager* GetControlsManager();
	static PhysicsManager* GetPhysicsManager();
	static SoundsManager* GetSoundsManager();
	static GraphicsManager* GetGraphicsManager();

}; // Game

#endif // __GAME_H__