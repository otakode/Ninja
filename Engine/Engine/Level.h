#ifndef __LEVEL_H__
#define __LEVEL_H__

class Level;

#include "Entity.h"

class Level
{
public:
	Entity root;

public:
	Level();
	virtual ~Level();
}; // Level

#endif // __LEVEL_H__