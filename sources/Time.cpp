#include "stdafx.h"
#include "Time.h"

float	Time::__speed = 5.0f;
float	Time::__now = 0.0f;
const float&	Time::speed = Time::__speed;
const float&	Time::now = Time::__now;

Time::Time() : _lastTime(Time::now)
{
}

Time::~Time()
{
}

void	Time::UpdateTime()
{
	Time::__now = (float)timeGetTime() / 1000.0f;
}

float	Time::Elapsed()
{
	float	elapsed = (Time::now - this->_lastTime) * Time::speed;
	this->_lastTime = Time::now;
	return elapsed;
}