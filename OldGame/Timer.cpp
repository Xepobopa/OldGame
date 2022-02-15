#include "Timer.h"

Timer::Timer() : PrintStuff("font//Paper.otf", 25)
{
	this->timeStop = 0;
	this->frameTime = 0;

	text.setFillColor(sf::Color::Black);
}

void Timer::setTime(float frametime)
{
	this->frameTime = frametime;
	text.setPosition(900 - text.getCharacterSize() * text.getString().getSize(), 10);
	this->text.setString("Timer: " + std::to_string((int)floor(frametime)) + "/" + std::to_string(timeStop));
}

void Timer::setTimeStop(int timeStop)
{
	this->timeStop = timeStop;
}

bool Timer::checkTimeStop()
{
	if (frameTime >= timeStop) { return true; };
	return false;
}

