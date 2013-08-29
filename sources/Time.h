#ifndef __TIME_H__
#define	__TIME_H__

#include <windows.h>
#include <mmsystem.h>

class	Time
{
private:
	static float	__speed;
	static float	__now;

public:
	static const float&	speed;
	static const float&	now;

protected:
	float	_lastTime;

public:
	Time();
	virtual ~Time();

	static void	UpdateTime();

	float	Elapsed();

};

#endif // __TIME_H__