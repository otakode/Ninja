#include "stdafx.h"
#include "Screen.h"

Screen::Screen(int width, int height)
{
	this->surface = SDL_SetVideoMode(width, height, 32, SDL_HWSURFACE);
}

Screen::~Screen()
{
	this->surface = NULL;
}

void	Screen::SetTitle(const char* title)
{
	SDL_WM_SetCaption(title, NULL);
}