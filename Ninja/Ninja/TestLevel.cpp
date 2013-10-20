#include "TestLevel.h"

TestLevel::TestLevel()
{
}

TestLevel::~TestLevel()
{
}

void TestLevel::Load()
{
	Entity* background = new Entity(&this->root, 0, 0);
	Graphic* backgroundGraphic = new Graphic(800, 600, 0xFF0000FF);
	background->AddComponent((Component*)backgroundGraphic);
	Entity* ground = new Entity(&this->root, 0, 300);
	Graphic* groundGraphic = new Graphic(800, 300, 0xFF00FF00);
	background->AddComponent((Component*)groundGraphic);
	Entity* player = new Entity(ground, 0, -50);
	Graphic* playerGraphic = new Graphic(50, 50, 0xFFFF0000);
	background->AddComponent((Component*)playerGraphic);

	this->root.AddChild(0, background);
	this->root.AddChild(5, ground);
	ground->AddChild(5, player);
}

void TestLevel::UnLoad()
{

}