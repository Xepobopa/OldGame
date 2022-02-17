#pragma once
#include<SFML/Graphics.hpp>

class Character
{
private:
	sf::Vector2f pos;
	sf::Texture* texture;
	sf::Sprite* sprite;
public:
	Character(sf::Vector2f pos, std::string path);
	Character(std::string path);

	sf::Sprite getCharacter();
	sf::Vector2f getPosition();
	sf::Vector2f getSize();
	void halfTransparent();
	void NotTransparent();
	void setPosition(sf::Vector2f pos);
	void moveRight();
	void moveLeft();
	void moveTop();
	void moveBottom();

	~Character();
};

