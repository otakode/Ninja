#include "stdafx.h"
#include "View.h"
#include "Game.h"

View::View()
{
	this->screen = new Screen(800, 600);
}

View::~View()
{
}

bool	View::Init(Game* game, const char* name)
{
	this->_game = game;

	if (this->screen->surface == NULL)
		return false;
	this->screen->SetTitle(name);

	return true;
}

void	View::Run()
{
//	this->screen->Draw();
	SDL_Flip(this->screen->surface);
}