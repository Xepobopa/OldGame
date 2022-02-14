#include "Timer.h"

Timer::Timer()
{
	frametime += clock.getElapsedTime().asSeconds();
	
}

float Timer::getTime()
{
	return this->frametime;
}
