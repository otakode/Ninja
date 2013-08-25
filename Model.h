#ifndef __MODEL_H__
#define __MODEL_H__

#include <SDL/SDL.h>
#include "Thread.h"
#include "View.h"
#include "Background.h"
#include "Character.h"


class	Game;

class	Model : public Thread
{
protected:
	Game*	_game;
	View*	_view;

public:
	Background	background;
	Character	player;

public:
	Model();
	virtual	~Model();

	bool	Init(Game* game, View* view);

protected:
	virtual void	_Run();

};

#endif // __MODEL_H__