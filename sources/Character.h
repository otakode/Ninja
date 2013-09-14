#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include "Entity.h"
#include "Surface.h"
#include "Time.h"

class	Character : public Entity
{
protected:
	float	_speed;
	float	_dir;
	float	_jumping;

public:
	float	x;
	float	y;

public:
	Character();
	virtual	~Character();

	void	Move(float dir);
	void	Jump();

	void	Update();

protected:

};


#endif // __CHARACTER_H__