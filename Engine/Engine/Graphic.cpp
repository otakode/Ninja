#include "Graphic.h"
#include "Game.h"

Graphic::Graphic(SDL_Surface* ptr) : Component(Type::GRAPHIC), surface(_surface), position(_position), dimension(_dimension), _position(0, 0), _dimension(0, 0)
{
	this->_surface = ptr;
	this->Init();
}

Graphic::Graphic(int width, int height, int color) : Component(Type::GRAPHIC), surface(_surface), position(_position), dimension(_dimension), _position(0, 0), _dimension(0, 0)
{
	this->_surface = SDL_CreateRGBSurface(SDL_HWSURFACE | SDL_SRCALPHA, width, height, 32, 0, 0, 0, 0);
	if (this->Init())
		this->Fill(color);
}

Graphic::Graphic(const char* path) : Component(Type::GRAPHIC), surface(_surface), position(_position), dimension(_dimension), _position(0, 0), _dimension(0, 0)
{
	this->_surface = SDL_LoadBMP(path);
	this->Init();
}

Graphic::Graphic(Graphic& model) : Component(Type::GRAPHIC), surface(_surface), position(_position), dimension(_dimension), _position(0, 0), _dimension(0, 0)
{
	this->_surface = SDL_CreateRGBSurface(model.surface->flags, model.surface->w, model.surface->h, model.surface->format->BitsPerPixel, model.surface->format->Rmask, model.surface->format->Gmask, model.surface->format->Bmask, model.surface->format->Amask);
	if (this->Init(model.position.x, model.position.y, model.dimension.x, model.dimension.y))
		this->Blit(model);
}

Graphic::~Graphic()
{
	Game::graphics.UnRegister(this);
	if (this->surface != NULL)
	{
		SDL_FreeSurface(this->surface);
		this->_surface = NULL;
	}
}

bool Graphic::Init(int x, int y, int w, int h)
{
	this->_position.x = x;
	this->_position.y = y;
	this->_dimension.x = w;
	this->_dimension.y = h;

	Game::graphics.Register(this);

	if (this->_surface == NULL)
		return false;

	if (w == -1)
		this->_dimension.x = this->_surface->w;
	if (h == -1)
		this->_dimension.y = this->_surface->h;

	return true;
}

void Graphic::Fill(int color)
{
	SDL_Rect rect;
	rect.x = this->position.x;
	rect.y = this->position.y;
	rect.w = this->dimension.x;
	rect.h = this->dimension.y;
	SDL_FillRect(this->_surface, &rect, color);
}

void Graphic::Blit(Graphic& other, Vector2<int> p)
{
	SDL_Rect chunk;
	chunk.x = other.position.x;
	chunk.y = other.position.y;
	chunk.w = other.dimension.x;
	chunk.h = other.dimension.y;
	SDL_Rect pos;
	pos.x = p.x;
	pos.y = p.y;
	SDL_BlitSurface(other.surface, &chunk, this->_surface, &pos);
}