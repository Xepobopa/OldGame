#pragma once
#include "Character.h"
#include "PrintStuff.h"
#include <iostream>
class SpaceDelay : public Character, public PrintStuff
{
private:
	float current_time;
public:
	SpaceDelay();

	// Set current time
	void setCurrentTime(float time);
	// check 2 sec. delay and return True if passed more 2 sec. Also print difference
	bool checkTimeTrue(float globalTime);
};

