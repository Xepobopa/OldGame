#include "Timer.h"

Timer::Timer()
{
	this->font.loadFromFile("font//Paper.otf");

	this->frameTime = 0;
	this->text = sf::Text("0", font, 23);
	this->text.setFillColor(sf::Color::Black);
	text.setPosition(900 - text.getCharacterSize() * text.getString().getSize(), 10);
}

sf::Text Timer::getText()
{
	return this->text;
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

