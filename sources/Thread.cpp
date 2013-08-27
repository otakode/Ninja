#include "stdafx.h"
#include "Thread.h"

Thread::Thread()
{
}

Thread::~Thread()
{
}

bool	Thread::Run()
{
	this->_running = false;
	if (this->_Init() == false)
		return false;

	this->_running = true;
	this->_hthread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)this->__Routine, (void*)this, 0, 0);

	return true;
}

void	Thread::Quit()
{
	this->_running = false;
}

HANDLE	Thread::GetThread()
{
	return this->_hthread;
}

bool	Thread::_Init()
{
	return true;
}

void	Thread::_Run()
{
}

long unsigned int	Thread::__Routine(void* ptr)
{
	Thread*	thread = (Thread*)ptr;

	thread->_Run();
	return 0;
}