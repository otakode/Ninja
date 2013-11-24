#ifndef __GRAPHICSMANAGER_H__
#define __GRAPHICSMANAGER_H__

class GraphicsManager;

#include "Manager.h"
#include "Screen.h"

class GraphicsManager : public Manager
{
private:
	Screen _screen;

protected:
	std::list<Component*> _registry;

public:
	const Screen& screen;

public:
	GraphicsManager();
	virtual ~GraphicsManager();

	void Register(Component* c);
	void UnRegister(Component* c);

	virtual bool Routine();

}; // GraphicsManager

#endif // __GRAPHICSMANAGER_H__