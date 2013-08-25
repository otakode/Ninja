#include "Model.h"
#include "Game.h"

Model::Model()
{
}

Model::~Model()
{
}

bool	Model::Init(Game* game, View* view)
{
	this->_game = game;
	this->_view = view;

	this->player.rect.y = 200;

	this->_view->screen.AddChild(&this->background);
	this->_view->screen.AddChild(&this->player);

	return true;
}

void	Model::_Run()
{
	while (this->_running)
	{
		Sleep(10);
		this->player.Update();
	}
}