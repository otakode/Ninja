#ifndef __GRAPHICSMANAGER_H__
#define __GRAPHICSMANAGER_H__

class GraphicsManager;

#include "Manager.h"

class GraphicsManager : public Manager
{
public:
	GraphicsManager();
	virtual ~GraphicsManager();

	virtual bool validComponent(Component::Type type);
}; // GraphicsManager

#endif // __GRAPHICSMANAGER_H__