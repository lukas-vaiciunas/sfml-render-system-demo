#include "GameText.h"

GameText::GameText() :
	text_()
{}

void GameText::setString(const sf::String &string)
{
	text_.setString(string);
}

void GameText::setFont(const sf::Font &font)
{
	text_.setFont(font);
}

void GameText::setCharacterSize(unsigned int characterSize)
{
	text_.setCharacterSize(characterSize);
}

void GameText::setFillColor(const sf::Color &color)
{
	text_.setFillColor(color);
}

void GameText::setOutlineColor(const sf::Color &color)
{
	text_.setOutlineColor(color);
}

void GameText::setOutlineThickness(float thickness)
{
	text_.setOutlineThickness(thickness);
}

void GameText::setPosition(const sf::Vector2f &position)
{
	text_.setPosition(position);
}

void GameText::setOrigin(const sf::Vector2f &origin)
{
	text_.setOrigin(origin);
}

unsigned int GameText::getCharacterSize() const
{
	return text_.getCharacterSize();
}

sf::FloatRect GameText::getLocalBounds() const
{
	return text_.getLocalBounds();
}