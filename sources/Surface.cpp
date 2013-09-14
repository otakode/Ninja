#include "stdafx.h"
#include "Surface.h"

Surface::Surface(int width, int height, int color) : Component(Component::SURFACE)
{
	this->surface = SDL_CreateRGBSurface(SDL_HWSURFACE | SDL_SRCALPHA, width, height, 32, 0, 0, 0, 0);
	if (this->Init())
		SDL_FillRect(this->surface, &this->chunk, color);
}

Surface::Surface(const char* imgPath) : Component(Component::SURFACE)
{
	this->surface = SDL_LoadBMP(imgPath);
	this->Init();
}

Surface::Surface(SDL_Surface* ptr) : Component(Component::SURFACE)
{
	this->surface = ptr;
	this->Init();
}

Surface::Surface(Surface& model) : Component(Component::SURFACE)
{
	this->surface = SDL_CreateRGBSurface(model.surface->flags, model.surface->w, model.surface->h, model.surface->format->BitsPerPixel, model.surface->format->Rmask, model.surface->format->Gmask, model.surface->format->Bmask, model.surface->format->Amask);
	if (this->Init(&model.chunk))
		this->Blit(&model);
}

Surface::~Surface()
{
	if (this->surface != NULL)
	{
		SDL_FreeSurface(this->surface);
		this->surface = NULL;
	}
}

bool	Surface::Init(int w, int h, int offx, int offy)
{
	this->chunk.x = offx;
	this->chunk.y = offy;
	this->chunk.w = w;
	this->chunk.h = h;

	if (this->surface == NULL)
		return false;

	if (w == -1)
		this->chunk.w = this->surface->w;
	if (h == -1)
		this->chunk.h = this->surface->h;

	return true;
}

bool	Surface::Init(SDL_Rect* chunk)
{
	this->chunk = *chunk;
	return true;
}

void	Surface::Clear()
{
	SDL_FillRect(this->surface, &this->chunk, SDL_MapRGBA(this->surface->format, 0, 0, 0, 0));
}

void	Surface::Blit(Surface* surface, SDL_Rect* pos, SDL_Rect* chunk)
{
	SDL_BlitSurface(surface->surface, chunk, this->surface, pos);
}

/*void	Surface::Draw()
{
	if (this->_children.empty())
		return;
	this->Clear();
	for (std::list<Surface*>::iterator it = this->_children.begin(), e = this->_children.end(); it != e; ++it)
	{
		Surface*	surface = *it;
		surface->Draw();
		this->Blit(surface, &surface->pos, &surface->chunk);
	}
}*/