#ifndef __SCREEN_H__
#define __SCREEN_H__

#include "Surface.h"

class	Screen : public Surface
{
public:
	Screen(int width, int height);
	virtual	~Screen();

	void	SetTitle(const char* title);
};


#endif // __SCREEN_H__