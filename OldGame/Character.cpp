#include "Character.h"

Character::Character(sf::Vector2f pos, std::string path)
{
	this->pos = pos;

	this->texture = new sf::Texture;
	this->texture->loadFromFile(path);

	this->sprite = new sf::Sprite(*texture);
	this->sprite->setPosition(pos);

	this->speed = 5;
}

Character::Character(std::string path)
{
	this->speed = 5;

	this->texture = new sf::Texture;
	this->texture->loadFromFile(path);

	this->sprite = new sf::Sprite(*texture);
}

sf::Sprite Character::getCharacter()
{
	return *this->sprite;
}

void Character::setPosition(sf::Vector2f pos)
{
	this->sprite->setPosition(pos);
}

sf::Vector2f Character::getSize()
{
	return this->sprite->getScale();
}

void Character::setSpeed(int speed)
{
	this->speed = speed;
}

void Character::NotTransparent()
{
	this->sprite->setColor(sf::Color(255, 255, 255, 255));
}

void Character::transparent()
{
	this->sprite->setColor(sf::Color(255, 255, 255, 0));
}

void Character::halfTransparent()
{
	this->sprite->setColor(sf::Color(255, 255, 255, 128));
}

sf::Vector2f Character::getPosition()
{
	return this->pos;
}

void Character::moveRight()
{
	if (pos.x <= 900 - 37) { this->pos = sf::Vector2f(pos.x + speed, pos.y); }
	this->sprite->setPosition(pos);
}

void Character::moveLeft()
{
	if (pos.x >= 0) { this->pos = sf::Vector2f(pos.x - speed, pos.y); }
	this->sprite->setPosition(pos);
}

void Character::moveTop()
{
	if (pos.y >= 0) { this->pos = sf::Vector2f(pos.x, pos.y - speed); }
	this->sprite->setPosition(pos);
}

void Character::moveBottom()
{
	if (pos.y <= 900 - 50) { this->pos = sf::Vector2f(pos.x, pos.y + speed); }
	this->sprite->setPosition(pos);
}

Character::~Character()
{
	delete sprite, texture;
}
