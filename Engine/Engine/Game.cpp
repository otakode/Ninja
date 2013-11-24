#include "Game.h"
#include "Time.h"

Game* Game::_instance = NULL;

Game::Game() : level(NULL), controls(NULL), physics(NULL), sounds(NULL), graphics(NULL)
{
	Game::_instance = this;
	this->controls = new ControlsManager();
	this->physics = new PhysicsManager();
	this->sounds = new SoundsManager();
	this->graphics = new GraphicsManager();
}

Game::~Game()
{
	if (Game::_instance == this)
		Game::_instance = NULL;
	if (this->controls != NULL)
		delete this->controls;
	if (this->physics != NULL)
		delete this->physics;
	if (this->sounds != NULL)
		delete this->sounds;
	if (this->graphics != NULL)
		delete this->graphics;
}

bool Game::Init()
{
	return true;
}

void Game::Run()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	if (this->Init() == false)
		return;
	this->running = true;
	while (this->running)
	{
		Time::UpdateTime();
		if (this->controls->Routine() == false)
			break;
		this->physics->Routine();
		this->sounds->Routine();
		this->graphics->Routine();
	}
	SDL_Quit();
}

void Game::Quit()
{
	if (Game::_instance != NULL)
	{
		Game::_instance->running = false;
	}
}

void Game::LoadLevel(Level* level)
{
	if (Game::_instance != NULL)
	{
		if (Game::_instance->level != NULL)
		{
			Game::_instance->level->UnLoad();
		}
		Game::_instance->level = level;
		level->Load();
	}
}

Level* Game::GetCurrentLevel()
{
	if (Game::_instance != NULL)
		return Game::_instance->level;
	return NULL;
}

ControlsManager* Game::GetControlsManager()
{
	if (Game::_instance != NULL)
		return Game::_instance->controls;
	return NULL;
}

PhysicsManager* Game::GetPhysicsManager()
{
	if (Game::_instance != NULL)
		return Game::_instance->physics;
	return NULL;
}

SoundsManager* Game::GetSoundsManager()
{
	if (Game::_instance != NULL)
		return Game::_instance->sounds;
	return NULL;
}

GraphicsManager* Game::GetGraphicsManager()
{
	if (Game::_instance != NULL)
		return Game::_instance->graphics;
	return NULL;
}