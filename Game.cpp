#include "Game.h"
 #include <iostream>
Game::Game()
{
}

Game::~Game()
{
}

bool	Game::Init()
{
	if (SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO) != 0)
		return false;

	this->__view.Init(this, "Ninja");
	this->__model.Init(this, &this->__view);
	this->__controller.Init(&this->__model);

	return true;
}

void	Game::Run()
{
	this->__view.Run();
	this->__model.Run();
	this->__controller.Run();

	this->Quit();
}

void	Game::Quit()
{
	this->__model.Quit();
	this->__view.Quit();

	WaitForSingleObject(this->__view.GetThread(), INFINITE);
	WaitForSingleObject(this->__model.GetThread(), INFINITE);

	SDL_Quit();
}