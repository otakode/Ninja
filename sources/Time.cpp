#include "stdafx.h"
#include "Time.h"
#include <iostream>

float	Time::__speed = 1.0f;
float	Time::__now = 0.0f;
float&	Time::speed = Time::__speed;
float&	Time::now = Time::__now;

Time::Time() : _lastTime(Time::now)
{
}

Time::~Time()
{
}

void	Time::UpdateTime()
{
	Time::__now = time(NULL) * 60 * 60 * 3600;
}

float	Time::Elapsed()
{
	float	elapsed = (Time::now - this->_lastTime) * Time::speed;
	this->_lastTime = Time::now;
	return elapsed;
}