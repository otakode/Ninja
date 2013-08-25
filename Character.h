#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include "Surface.h"

class	Character : public Surface
{
protected:
	int	_speed;
	int	_dir;
	int	_jumping;

public:
	Character();
	virtual	~Character();

	void	Move(int dir);
	void	Jump();

	void	Update();

protected:

};


#endif // __CHARACTER_H__