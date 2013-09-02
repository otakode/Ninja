#include "stdafx.h"
#include "Game.h"
#include "Time.h"

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

	this->__running = true;

	if (this->__view.Init(this, "Ninja") == false)
		return false;
	if (this->__model.Init(this, &this->__view) == false)
		return false;
	if (this->__controller.Init(this, &this->__model) == false)
		return false;

	return true;
}

void	Game::Run()
{
	//this->__controller.Run();
	//this->__model.Run();
	//this->__view.Run();
	while (this->__running)
	{
		this->__controller.Run();
		if (Time::UpdateTime())
		{
			this->__model.Run();
			this->__view.Run();
		}
	}
	SDL_Quit();
}

void	Game::Quit()
{
	this->__running = false;
	
//	this->__controller.Quit();
//	this->__model.Quit();
//	this->__view.Quit();
	
//	WaitForSingleObject(this->__controller.GetThread(), INFINITE);
//	WaitForSingleObject(this->__model.GetThread(), INFINITE);
//	WaitForSingleObject(this->__view.GetThread(), INFINITE);

}