#ifndef __SOUNDSMANAGER_H__
#define __SOUNDSMANAGER_H__

class SoundsManager;

#include "Manager.h"

class SoundsManager : public Manager
{
public:
	SoundsManager();
	virtual ~SoundsManager();

	virtual bool validComponent(Component::Type type);
}; // SoundsManager

#endif // __SOUNDSMANAGER_H__