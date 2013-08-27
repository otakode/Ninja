#ifndef __THREAD_H__
#define __THREAD_H__

#include <windows.h>
#include <process.h>
#include <stdlib.h>

class	Thread
{
protected:
	HANDLE	_hthread;
	bool	_running;

public:
	Thread();
	virtual	~Thread();

	bool	Run();
	void	Quit();

	HANDLE	GetThread();

protected:
	virtual bool	_Init();
	virtual void	_Run();

private:
	static long unsigned int	__Routine(void*);

};

#endif // __THREAD_H__