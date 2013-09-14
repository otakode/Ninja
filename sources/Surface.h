#ifndef __SURFACE_H__
#define __SURFACE_H__

#include <SDL.h>
#include <list>

#include "Component.h"

class	Surface : public Component
{
public:
	SDL_Surface*	surface;
	SDL_Rect		chunk;

public:
	Surface(SDL_Surface* ptr = NULL);
	Surface(int width, int height, int color = 0x00000000);
	Surface(const char* imgPath);
	Surface(Surface& model);
	virtual	~Surface();

	bool	Init(int w = -1, int h = -1, int offx = 0, int offy = 0);
	bool	Init(SDL_Rect* chunk);

	void	Clear();
	void	Blit(Surface* surface, SDL_Rect* pos = NULL, SDL_Rect* chunk = NULL);
//	void	Draw();

protected:

}; // Surface


#endif // __SURFACE_H__