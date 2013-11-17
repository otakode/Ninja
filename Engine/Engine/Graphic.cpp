#include "Graphic.h"
#include "Game.h"

Graphic::Graphic(SDL_Surface* ptr) : Component(Type::GRAPHIC),/* surface(_surface),*/ position(_position), dimension(_dimension), _surface(NULL), _position(0, 0), _dimension(0, 0)
{
	this->_surface = ptr;
	this->Init();
}

Graphic::Graphic(int width, int height, int color) : Component(Type::GRAPHIC),/* surface(_surface),*/ position(_position), dimension(_dimension), _surface(NULL), _position(0, 0), _dimension(0, 0)
{
	this->_surface = SDL_CreateRGBSurface(SDL_HWSURFACE | SDL_SRCALPHA, width, height, 32, 0, 0, 0, 0);
	if (this->Init())
		this->Fill(color);
}

Graphic::Graphic(const char* path) : Component(Type::GRAPHIC), /*surface(_surface),*/ position(_position), dimension(_dimension), _surface(NULL), _position(0, 0), _dimension(0, 0)
{
	this->_surface = SDL_LoadBMP(path);
	this->Init();
}

Graphic::Graphic(Graphic& model) : Component(Type::GRAPHIC), /*surface(_surface),*/ position(_position), dimension(_dimension), _surface(NULL), _position(0, 0), _dimension(0, 0)
{
	this->_surface = SDL_CreateRGBSurface(model._surface->flags, model._surface->w, model._surface->h, model._surface->format->BitsPerPixel, model._surface->format->Rmask, model._surface->format->Gmask, model._surface->format->Bmask, model._surface->format->Amask);
	if (this->Init(model._position.x, model._position.y, model._dimension.x, model._dimension.y))
		this->Blit(&model);
}

Graphic::~Graphic()
{
	Game::GetGraphicsManager()->UnRegister(this);
	if (this->_surface != NULL)
	{
		SDL_FreeSurface(this->_surface);
		this->_surface = NULL;
	}
}

bool Graphic::Init(int x, int y, int w, int h)
{
	this->_position.x = x;
	this->_position.y = y;
	this->_dimension.x = w;
	this->_dimension.y = h;

	if (this->_surface == NULL)
		return false;

	GraphicsManager* manager = Game::GetGraphicsManager();
	if (manager != NULL)
		manager->Register(this);

	if (w == -1)
		this->_dimension.x = this->_surface->w;
	if (h == -1)
		this->_dimension.y = this->_surface->h;

	return true;
}

void Graphic::Fill(int color)
{
	SDL_Rect rect;
	rect.x = this->_position.x;
	rect.y = this->_position.y;
	rect.w = this->_dimension.x;
	rect.h = this->_dimension.y;
	SDL_FillRect(this->_surface, &rect, color);
}

void Graphic::Blit(Graphic* other, Vector2<int> p)
{
	if (this->_surface == NULL || other->_surface == NULL)
		return;
	SDL_Rect chunk;
	chunk.x = other->_position.x;
	chunk.y = other->_position.y;
	chunk.w = other->_dimension.x;
	chunk.h = other->_dimension.y;
	SDL_Rect pos;
	pos.x = p.x;
	pos.y = p.y;
	SDL_BlitSurface(other->_surface, &chunk, this->_surface, &pos);
}