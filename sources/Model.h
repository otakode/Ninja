#ifndef __MODEL_H__
#define __MODEL_H__

#include <SDL.h>
#include "Thread.h"
#include "View.h"
#include "Background.h"
#include "Character.h"
#include "Ground.h"
#include "Time.h"

class	Game;

class	Model
{
protected:
	Game*	_game;
	View*	_view;

public:
	Background	background;
	Character	player;
	Ground		ground;

public:
	Model();
	virtual	~Model();

	bool	Init(Game* game, View* view);
	void	Run();

};

#endif // __MODEL_H__