#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#include <SDL.h>
#include "Model.h"

class	Game;

class	Controller
{
protected:
	Game*	_game;
	Model*	_model;
	float	_dir;

public:
	Controller();
	virtual	~Controller();

	bool	Init(Game* game, Model* model);
	void	Run();

};

#endif // __CONTROLLER_H__