#include "TestLevel.h"
#include "PlayerController.h"

TestLevel::TestLevel()
{
}

TestLevel::~TestLevel()
{
}

void TestLevel::Load()
{
	Entity* background = new Entity(&this->root, 0, 0);
	this->root.AddChild(0, background);
	background->AddComponent(new Graphic(800, 600, 0xFF0000FF));

	Entity* ground = new Entity(&this->root, 0, 300);
	this->root.AddChild(5, ground);
	ground->AddComponent(new Graphic(800, 300, 0xFF008800));

	Entity* player = new Entity(ground, 0, -50);
	ground->AddChild(5, player);
	player->AddComponent(new Graphic(50, 50, 0xFFFF0000));
	Controller* playerControl = new PlayerController();
	Game::GetControlsManager()->RegisterToKey(playerControl, SDLK_RIGHT);
	Game::GetControlsManager()->RegisterToKey(playerControl, SDLK_LEFT);
	player->AddComponent(playerControl);
}

void TestLevel::UnLoad()
{

}