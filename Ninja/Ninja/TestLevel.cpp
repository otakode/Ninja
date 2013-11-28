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
	Entity* background = new Entity();
	this->root.AddChild(background, 0, Vector2<>(0, 0));
	background->AddComponent(new Graphic(800, 600, 0xFF4444FF));

	Entity* ground = new Entity();
	this->root.AddChild(ground, 5, Vector2<>(0, 300));
	ground->AddComponent(new Graphic(800, 300, 0xFF008800));

	Entity* player = new Entity();
	ground->AddChild(player, 5, Vector2<>(0, -50));
	player->AddComponent(new Graphic(50, 50, 0xFFFF0000));
	Controller* playerControl = new PlayerController();
	player->AddComponent(playerControl);
}

void TestLevel::UnLoad()
{

}