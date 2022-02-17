#pragma once
#include<SFML/Graphics.hpp>

class Character
{
private:
	sf::Vector2f pos;
	sf::Texture* texture;
	sf::Sprite* sprite;
	int speed;
public:
	Character(sf::Vector2f pos, std::string path);
	Character(std::string path);

	sf::Sprite getCharacter();
	sf::Vector2f getPosition();
	sf::Vector2f getSize();
	void setSpeed(int speed);
	void halfTransparent();
	void NotTransparent();
	void transparent();
	void setPosition(sf::Vector2f pos);
	void moveRight();
	void moveLeft();
	void moveTop();
	void moveBottom();

	~Character();
};

