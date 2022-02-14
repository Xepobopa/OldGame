#pragma once
#include<SFML/Graphics.hpp>
class Timer
{
private:
	sf::Clock clock;
	sf::Time time;
	sf::Texture texture;
	sf::Sprite sprite;
	float frametime = 0;
public:
	Timer();
	float getTime();
};

