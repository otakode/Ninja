#ifndef __SCREEN_H__
#define __SCREEN_H__

class Screen;

#include "Graphic.h"

class Screen : public Graphic
{
public:
	Screen(int width = 800, int height = 600);
	virtual ~Screen();

	void SetTitle(const char* title);
}; // Screen

#endif // __SCREEN_H__