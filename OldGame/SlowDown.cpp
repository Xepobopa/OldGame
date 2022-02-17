#include "SlowDown.h"

SlowDown::SlowDown(Character& ch) : Character("images//arrow.png")
{
	this->current_time = 0;
	arrow_pick = false;
	// create arrow to pick at random place
	this->pos = sf::Vector2f(rand() % 900, rand() % 900);
	arrow_to_pick = new Character(pos, "images//arrow.png");
	Character::transparent();
	Character::setPosition(sf::Vector2f(ch.getPosition().x + 15, ch.getPosition().y - 32));
}

Character* SlowDown::getArrowToPick()
{
	return this->arrow_to_pick;
}

void SlowDown::setActive(Character& ch)
{
	Character::NotTransparent();
	Character::setPosition(sf::Vector2f(ch.getPosition().x + 15, ch.getPosition().y - 32));
	this->arrow_pick = true;
	this->arrow_to_pick->transparent();
	this->pos = sf::Vector2f(NULL, NULL);
	ch.setSpeed(3);
}

void SlowDown::disable(Character& ch)
{
	this->arrow_pick = true;
	Character::transparent();
	//set default speed
	ch.setSpeed(5);
}

bool SlowDown::checkArrowPick()
{
	if (this->arrow_pick) { return true; }

	return false;
}

bool SlowDown::checkArrowToPickTouch(Character& ch)
{
	if (ch.getCharacter().getGlobalBounds().intersects(arrow_to_pick->getCharacter().getGlobalBounds())) { 
		return true;
		arrow_to_pick->transparent();
	}
	return false;
}

void SlowDown::setCurrentTime(float time)
{
	this->current_time = time;
}

bool SlowDown::checkTimeTrue(float globaltime)
{
	if (globaltime - current_time >= 4) {
		return true;
	}
	else { return false; }
}

