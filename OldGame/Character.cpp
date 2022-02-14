#include "Character.h"

Character::Character(sf::Vector2f pos, std::string path)
{
	this->pos = pos;

	this->texture = new sf::Texture;
	this->texture->loadFromFile(path);

	this->sprite = new sf::Sprite(*texture);
	this->sprite->setPosition(pos);
}

sf::Sprite Character::getCharacter()
{
	return *this->sprite;
}

void Character::moveRight()
{
	if (pos.x <= 900 - 37) { this->pos = sf::Vector2f(pos.x + 5, pos.y); }
	this->sprite->setPosition(pos);
}

sf::Vector2f Character::getPosition()
{
	return this->pos;
}


void Character::moveLeft()
{
	if (pos.x >= 0) { this->pos = sf::Vector2f(pos.x - 5, pos.y); }
	this->sprite->setPosition(pos);
}

void Character::moveTop()
{
	if (pos.y >= 0) { this->pos = sf::Vector2f(pos.x, pos.y - 5); }
	this->sprite->setPosition(pos);
}

void Character::moveBottom()
{
	if (pos.y <= 900 - 50) { this->pos = sf::Vector2f(pos.x, pos.y + 5); }
	this->sprite->setPosition(pos);
}

Character::~Character()
{
	delete sprite, texture;
}
