#pragma once

#include <SFML/Graphics/Text.hpp>

class GameText
{
public:
	GameText();

	void setString(const sf::String &string);
	void setFont(const sf::Font &font);
	void setCharacterSize(unsigned int characterSize);

	void setFillColor(const sf::Color &color);
	void setOutlineColor(const sf::Color &color);
	void setOutlineThickness(float thickness);

	void setPosition(const sf::Vector2f &position);

	void setOrigin(const sf::Vector2f &origin);

	unsigned int getCharacterSize() const;
	sf::FloatRect getLocalBounds() const;
protected:
	sf::Text text_;
};