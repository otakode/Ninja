#include "Surface.h"

Surface::Surface(int width, int height, int color)
{
	this->surface = SDL_CreateRGBSurface(SDL_HWSURFACE, width, height, 32, 0, 0, 0, 0);
	this->rect.x = 0;
	this->rect.y = 0;
	this->rect.w = width;
	this->rect.h = height;
	SDL_FillRect(this->surface, &this->rect, color);
}

Surface::Surface(const char* imgPath)
{
	this->surface = SDL_LoadBMP(imgPath);
}

Surface::Surface(SDL_Surface* ptr)
{
	this->surface = ptr;
}

Surface::Surface(Surface& model)
{
	this->surface = SDL_CreateRGBSurface(model.surface->flags, model.surface->w, model.surface->h, model.surface->format->BitsPerPixel, model.surface->format->Rmask, model.surface->format->Gmask, model.surface->format->Bmask, model.surface->format->Amask);
	this->rect.x = 0;
	this->rect.y = 0;
	this->rect.w = this->surface->w;
	this->rect.h = this->surface->h;
	this->Blit(&model, &this->rect);
}

Surface::~Surface()
{
	if (this->surface != NULL)
		SDL_FreeSurface(this->surface);
}

void	Surface::Blit(Surface* surf, SDL_Rect* destRect, SDL_Rect* srcRect)
{
	SDL_BlitSurface(surf->surface, srcRect, this->surface, destRect);
}

void	Surface::Draw()
{
	for (std::list<Surface*>::iterator it = this->_children.begin(), e = this->_children.end(); it != e; ++it)
	{
		Surface*	surface = *it;
		surface->Draw();
		this->Blit(surface, &surface->rect);
	}
}

void	Surface::AddChild(Surface* surface)
{
	this->_children.push_back(surface);
}

void	Surface::DelChild(Surface* surface)
{
	this->_children.remove(surface);
}