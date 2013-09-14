#include "stdafx.h"
#include "Ground.h"

Ground::Ground()
{
	this->AddComponent(new Surface(800, 300, 0x00AA00));
}

Ground::~Ground()
{
}