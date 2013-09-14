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

	this->player = new Character();
	this->player->y = 200;
	Ground*	ground = new Ground();
	ground->pos.y = 300;
	Background*	background = new Background();

	this->root = new Entity();
	this->root->AddComponent(this->_view->screen);
	this->root->AddChild(0, background);
	this->root->AddChild(5, ground);
	this->root->AddChild(6, this->player);

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
	this->player->Update();
	//this->root->components.find(Component::SURFACE);
	Surface* screen = (Surface*)this->root->GetComponent(Component::SURFACE);
	std::vector<Entity*> surfaces = this->root->GetChildWithComponent(Component::SURFACE);
	for (std::vector<Entity*>::iterator it = surfaces.begin() + 1, e = surfaces.end(); it != e; it++)
	{
		Entity* entity = *it;
		Surface* surface = (Surface*)entity->GetComponent(Component::SURFACE);
		screen->Blit(surface, &entity->GetAbsolutePos(), &surface->chunk);
	}
/*	char test[1000];
	sprintf(test, "%f", Time::elapsed);
	this->_view->screen.SetTitle(test);*/
}