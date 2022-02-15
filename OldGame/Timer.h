#pragma once
#include<cmath>
#include "PrintStuff.h"
#include<SFML/Graphics.hpp>
class Timer : public PrintStuff
{
private:
	int timeStop;
	int frameTime;
public:
	Timer();

	void setTime(float frametime);
	void setTimeStop(int timeStop);
	bool checkTimeStop();
};

