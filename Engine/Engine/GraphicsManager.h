#ifndef __GRAPHICSMANAGER_H__
#define __GRAPHICSMANAGER_H__

class GraphicsManager;

#include "Manager.h"
#include "Screen.h"

class GraphicsManager : public Manager
{
private:
	Screen _screen;

public:
	const Screen& screen;

public:
	GraphicsManager();
	virtual ~GraphicsManager();

	virtual bool Routine();

}; // GraphicsManager

#endif // __GRAPHICSMANAGER_H__