#ifndef __TESTLEVEL_H__
#define __TESTLEVEL_H__

class TestLevel;

#include "../../Engine/Engine/Level.h"
#include "../../Engine/Engine/Game.h"
#include "../../Engine/Engine/Graphic.h"
#include "../../Engine/Engine/Controller.h"

class TestLevel : public Level
{
public:
	TestLevel();
	virtual ~TestLevel();

	virtual void Load();
	virtual void UnLoad();

}; // TestLevel

#endif // __TESTLEVEL_H__