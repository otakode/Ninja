#include "View.h"
#include "Game.h"

View::View() : screen(800, 600)
{
}

View::~View()
{
}

bool	View::Init(Game* game, const char* name)
{
	this->_game = game;

	if (this->screen.surface == NULL)
		return false;
	this->screen.SetTitle(name);

	return true;
}

void	View::_Run()
{
	while (this->_running)
	{
		this->screen.Draw();
		SDL_Flip(this->screen.surface);
	}
}