#include "stdafx.h"
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
	this->ground.rect.y = 300;

	this->_view->screen.AddChild(&this->background);
	this->_view->screen.AddChild(&this->player);
	this->_view->screen.AddChild(&this->ground);

	return true;
}

void	Model::Run()
{
	Time::UpdateTime();
	this->player.Update();
}