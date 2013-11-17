#include "GraphicsManager.h"
#include "Game.h"

GraphicsManager::GraphicsManager() : Manager(Component::GRAPHIC), screen(_screen), _screen(800, 600)
{
}

GraphicsManager::~GraphicsManager()
{
}

bool GraphicsManager::Routine()
{
	Level* level = Game::GetCurrentLevel();
	if (level != NULL)
	{
		std::vector<Entity*> graphics = level->root.GetChildWithComponent(Component::GRAPHIC);
		for (size_t i = 0; i < graphics.size(); i++)
		{
			Graphic* graphic = (Graphic*)graphics[i]->GetComponent(Component::GRAPHIC);
			Vector2<> posFloat = graphics[i]->GetAbsolutePos();
			Vector2<int> posInt((int)posFloat.x, (int)posFloat.y);
			this->_screen.Blit(graphic, posInt);
		}
		this->_screen.Flip();
	}

	return true;
}