#ifndef __VIEW_H__
#define __VIEW_H__

#include <SDL/SDL.h>
#include "Thread.h"
#include "Screen.h"
#include "Surface.h"

class	Game;

class	View : public Thread
{
public:
	Screen	screen;
protected:
	Game*	_game;

public:
	View();
	virtual	~View();

	bool	Init(Game* game, const char* name);

protected:
	virtual void	_Run();

};

#endif // __VIEW_H__