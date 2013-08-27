#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include "Surface.h"
#include "Time.h"

class	Character : public Surface
{
protected:
	Time	_time;
	float	_speed;
	float	_dir;
	float	_jumping;

public:
	Character();
	virtual	~Character();

	void	Move(float dir);
	void	Jump();

	void	Update();

protected:

};


#endif // __CHARACTER_H__