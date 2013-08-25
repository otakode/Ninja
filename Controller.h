#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#include <SDL/SDL.h>
#include "Model.h"

class	Controller
{
protected:
	Model*	_model;
	int		_dir;

public:
	Controller();
	virtual	~Controller();

	bool	Init(Model* model);
	void	Run();

};

#endif // __CONTROLLER_H__