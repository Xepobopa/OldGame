#pragma once
#include "Character.h"
class SlowDown : public Character
{
private:
	float current_time;
	Character* arrow_to_pick;
	sf::Vector2f pos;
	bool arrow_pick;
public:
	SlowDown(Character& ch);

	Character* getArrowToPick();
	// make arrow visible, set needed position, and make character slower
	void setActive(Character& ch);
	// set normal speed and make arrow invisible
	void disable(Character& ch);
	// Set current time
	void setCurrentTime(float time);
	// check 2 sec. delay and return True if passed more 2 sec. Also print difference
	bool checkTimeTrue(float globaltime);
	bool checkArrowPick();
	bool checkArrowToPickTouch(Character& ch);
};

