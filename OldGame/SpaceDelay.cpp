#include "SpaceDelay.h"

SpaceDelay::SpaceDelay() : Character("images//hand.png"), PrintStuff("font//Paper.otf", 30)
{
	this->current_time = 0;
	Character::setPosition(sf::Vector2f(0, 0));
	PrintStuff::setPosition(sf::Vector2f(100, 0));
	PrintStuff::text.setFillColor(sf::Color::Black);
}

void SpaceDelay::setCurrentTime(float time)
{
	//this->setContent( std::to_string(time - current_time) + " / 2");
	this->current_time = time;
}

bool SpaceDelay::checkTimeTrue(float globalTime)
{
	this->setContent( std::to_string((int)floor(globalTime - current_time)) + " / 2" );
	if (globalTime - this->current_time >= 2) {
		this->setContent("");
		this->NotTransparent();
		return true;
	}
	else { return false; }
}
