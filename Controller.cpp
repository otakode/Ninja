#include "Controller.h"
#include "Game.h"

Controller::Controller()
{
}

Controller::~Controller()
{
}

bool	Controller::Init(Model* model)
{
	this->_model = model;
	this->_dir = 0;
	return true;
}

void	Controller::Run()
{
	SDL_Event	event;
	while (SDL_WaitEvent(&event))
	{
		if (event.type == SDL_QUIT)
		{
			break;
		}
		switch (event.type)
		{
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
					case SDLK_LEFT:
						this->_dir -= 1;
						break;
					case SDLK_RIGHT:
						this->_dir += 1;
						break;
					case SDLK_UP:
						this->_model->player.Jump();
						break;
					default:
						break;
				}
				this->_model->player.Move(this->_dir);
				break;
			case SDL_KEYUP:
				switch (event.key.keysym.sym)
				{
					case SDLK_LEFT:
						this->_dir += 1;
						break;
					case SDLK_RIGHT:
						this->_dir -= 1;
						break;
					case SDLK_UP:
						this->_model->player.Jump();
						break;
					default:
						break;
				}
				this->_model->player.Move(this->_dir);
				break;
			default:
				break;
		}
	}
}