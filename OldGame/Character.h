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

	sf::Sprite getCharacter();
	sf::Vector2f getPosition();
	void moveRight();
	void moveLeft();
	void moveTop();
	void moveBottom();

	~Character();
};

