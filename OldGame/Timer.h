#pragma once
#include<cmath>
#include<iostream>
#include<SFML/Graphics.hpp>
class Timer
{
private:
	sf::Font font;
	sf::Text text;
	int timeStop;
	int frameTime;
public:
	Timer();

	sf::Text getText();
	void setTime(float frametime);
	void setTimeStop(int timeStop);
	bool checkTimeStop();
};

