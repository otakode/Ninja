#ifndef __SURFACE_H__
#define __SURFACE_H__

#include <SDL/SDL.h>
#include <list>

class	Surface
{
protected:
	std::list<Surface*>	_children;

public:
	SDL_Rect		rect;
	SDL_Surface*	surface;

public:
	Surface(SDL_Surface* ptr = NULL);
	Surface(int width, int height, int color = 0x000000);
	Surface(const char* imgPath);
	Surface(Surface& model);
	virtual	~Surface();

	void	Blit(Surface* src, SDL_Rect* destRect, SDL_Rect* srcRect = NULL);
	void	Draw();

	void	AddChild(Surface* surface);
	void	DelChild(Surface* surface);

protected:

};


#endif // __SURFACE_H__