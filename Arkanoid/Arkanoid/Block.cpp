#include "Block.h"
#include "../../Engine/Engine/Graphic.h"

Block::Block()
{
	Graphic* graphic = new Graphic(60, 20, 0xFF000000 + ((rand() % 0xFF) << 16) + ((rand() % 0xFF) << 8) + (rand() % 0xFF));
	this->AddComponent(graphic);
}

Block::~Block()
{
}

