#include "Background.h"

Background::Background()
{
	this->texture = new sf::Texture;
	texture->loadFromFile("images//bg.png");

	this->sprite = new sf::Sprite(*texture);
}

sf::Sprite Background::getBackground()
{
	return *this->sprite;
}

Background::~Background()
{
	delete texture, sprite;
}
