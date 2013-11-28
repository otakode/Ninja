#include "TestLevel.h"
#include "Block.h"
#include "Player.h"

TestLevel::TestLevel()
{
}

TestLevel::~TestLevel()
{
}

void TestLevel::Load()
{
	Entity* background = new Entity();
	background->AddComponent(new Graphic(800, 600, 0));
	this->root.AddChild(background, 0, Vector2<>(0, 0));
	for (int i = 0; i < 50; ++i)
	{
		this->root.AddChild(new Block(), 1, Vector2<>(100 + (i % 10) * 60, 50 + i / 10 * 20));
	}
	this->root.AddChild(new Player(), 2, Vector2<>(400 - 40, 600 - 40));
	// create ball
}

void TestLevel::UnLoad()
{

}