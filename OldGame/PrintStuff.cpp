#include "PrintStuff.h"

PrintStuff::PrintStuff(std::string fontPath, int contentSize)
{
	this->font.loadFromFile(fontPath);
	this->text = sf::Text(content, font, contentSize);
}

void PrintStuff::setPosition(sf::Vector2f pos)
{
	this->text.setPosition(pos);
}

void PrintStuff::setContentSize(int size)
{
	this->text.setCharacterSize(size);
}

void PrintStuff::setContent(std::string content)
{
	this->text.setString(content);
}

sf::Text PrintStuff::getText()
{
	return this->text;
}
