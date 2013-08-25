#ifndef __GAME_H__
#define __GAME_H__

#include <windows.h>
#include <unistd.h>
#include <SDL/SDL.h>
#include "Controller.h"
#include "Model.h"
#include "View.h"

class	Game
{
private:
	Controller	__controller;
	Model		__model;
	View		__view;

public:

	Game();
	virtual ~Game();

	bool	Init();
	void	Run();
	void	Quit();

};

#endif // __GAME_H__
