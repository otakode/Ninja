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

/*	for (int i = 0; i < 10000; i++)
	{
		this->root.AddChild(0, new Entity());
		this->root.DelChild(this->root.children.begin()->second);
		char toto[100];
		sprintf(toto, "%i", this->root.children.size());
		this->_view->screen.SetTitle(toto);
	}
	for (int i = 0; i < 10000; i++)
	{
		this->root.AddComponent(new Component(Component::NONE));
		this->root.DelComponent(this->root.components.begin()->second);
		char toto[100];
		sprintf(toto, "%i", this->root.components.size());
		this->_view->screen.SetTitle(toto);
	}*/

	return true;
}

void	Model::Run()
{
	this->player.Update();
/*	char test[1000];
	sprintf(test, "%f", Time::elapsed);
	this->_view->screen.SetTitle(test);*/
}