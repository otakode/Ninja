#ifndef __PIXELMASK_H__
#define __PIXELMASK_H__

#include "../Body.h"

class PixelMask : public Body
{
public:
	PixelMask();
	PixelMask(Type type);
	virtual ~PixelMask();

}; // PixelMask

#endif // __PIXELMASK_H__