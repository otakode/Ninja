#include "stdafx.h"
#include "Background.h"

Background::Background()
{
	this->AddComponent(new Surface(800, 600, 0x8888FF));
}

Background::~Background()
{
}