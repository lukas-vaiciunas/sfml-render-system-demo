#pragma once

#include "TextureId.h"
#include <SFML/Graphics/Sprite.hpp>

class GameSprite
{
public:
	GameSprite(TextureId textureId);

	void setPosition(const sf::Vector2f &position);

	sf::FloatRect getLocalBounds() const;
protected:
	sf::Sprite sprite_;
};