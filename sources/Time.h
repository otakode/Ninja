#ifndef __TIME_H__
#define	__TIME_H__

#include <windows.h>
#include <mmsystem.h>

class	Time
{
private:
	static float	__speed;
	static float	__now;
	static float	__lastTime;
	static float	__elapsed;

public:
	static const float&	speed;
	static const float&	now;
	static const float&	elapsed;

public:
	Time();
	virtual ~Time();

	static bool	UpdateTime();
};

#endif // __TIME_H__