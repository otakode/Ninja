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

	this->player.y = 200;
	this->ground.pos.y = 300;

	this->_view->screen.AddChild(&this->background);
	this->_view->screen.AddChild(&this->player);
	this->_view->screen.AddChild(&this->ground);

	return true;
}

void	Model::Run()
{
	this->player.Update();
/*	char test[1000];
	sprintf(test, "%f", Time::elapsed);
	this->_view->screen.SetTitle(test);*/
}