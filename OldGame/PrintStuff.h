#pragma once
#include<SFML/Graphics.hpp>
class PrintStuff
{
protected:
	sf::Font font;
	sf::Text text;
	std::string content;
	sf::Vector2f position;
public:
	// create Text to print in the window
	PrintStuff(std::string fontPath, int contentSize);

	void setPosition(sf::Vector2f pos);
	void setContentSize(int size);
	void setContent(std::string content);
	sf::Text getText();
};

