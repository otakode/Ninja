#include "Screen.h"

Screen::Screen(int width, int height) : Graphic(SDL_SetVideoMode(width, height, 32, SDL_HWSURFACE | SDL_DOUBLEBUF))
{
}

Screen::~Screen()
{
	this->_surface = NULL;
}

void Screen::SetTitle(const char* title)
{
	SDL_WM_SetCaption(title, NULL);
}

void Screen::Flip()
{
	if (this->_surface != NULL)
		SDL_Flip(this->_surface);
}