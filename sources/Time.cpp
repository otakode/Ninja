#include "stdafx.h"
#include "Time.h"

float	Time::__speed = 1.0f;
float	Time::__now = 0.0f;
float	Time::__lastTime = 0.0f;
float	Time::__elapsed = 0.0f;
const float&	Time::speed = Time::__speed;
const float&	Time::now = Time::__now;
const float&	Time::elapsed= Time::__elapsed;

Time::Time()
{
}

Time::~Time()
{
}

bool	Time::UpdateTime()
{
	Time::__now = (float)timeGetTime() * 0.001f;

	Time::__elapsed = Time::now - Time::__lastTime;
	if (Time::elapsed < 0.0167f)
		return false;
	if (Time::elapsed > 0.3f)
		Time::__elapsed = 0.3f;
	Time::__lastTime = Time::now;
	Time::__elapsed *= Time::speed;
	return true;
}