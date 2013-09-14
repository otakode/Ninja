#ifndef __MODEL_H__
#define __MODEL_H__

#include <SDL.h>
//#include "Thread.h"
#include "View.h"
//#include "Time.h"
#include "Entity.h"
#include "Background.h"
#include "Ground.h"
#include "Character.h"

class	Game;

class	Model
{
protected:
	Game*	_game;
	View*	_view;

public:
	Entity*		root;
	Character*	player;

public:
	Model();
	virtual	~Model();

	bool	Init(Game* game, View* view);
	void	Run();

}; // Model

#endif // __MODEL_H__