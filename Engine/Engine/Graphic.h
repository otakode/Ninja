#ifndef __GRAPHIC_H__
#define __GRAPHIC_H__

class Graphic;

#include "Component.h"
#include <SDL/SDL.h>
#include "Vector2.h"

class Graphic : public Component
{
protected:
	SDL_Surface* _surface;
	Vector2<int> _position;
	Vector2<int> _dimension;

public:
	SDL_Surface* const surface;
	const Vector2<int>& position;
	const Vector2<int>& dimension;

public:
	Graphic(SDL_Surface* ptr = NULL);
	Graphic(int width, int height, int color = 0x00000000);
	Graphic(const char* path);
	Graphic(Graphic& model);
	virtual ~Graphic();

	bool Init(int x = 0, int y = 0, int w = -1, int h = -1);

	void Fill(int color);
	void Blit(Graphic& other, Vector2<int> pos = Vector2<int>(0, 0));
}; // Graphic

#endif // __GRAPHIC_H__