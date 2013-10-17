#ifndef __CONTROLSMANAGER_H__
#define __CONTROLSMANAGER_H__

class ControlsManager;

#include "Manager.h"

class ControlsManager : public Manager
{
public:
	ControlsManager();
	virtual ~ControlsManager();

	virtual bool validComponent(Component::Type type);
}; // ControlsManager

#endif // __CONTROLSMANAGER_H__