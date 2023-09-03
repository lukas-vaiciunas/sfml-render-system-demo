#include "GameSprite.h"
#include "TextureData.h"

GameSprite::GameSprite(TextureId textureId) :
	sprite_(TextureData::getInstance().getTexture(textureId))
{}

void GameSprite::setPosition(const sf::Vector2f &position)
{
	sprite_.setPosition(position);
}

sf::FloatRect GameSprite::getLocalBounds() const
{
	return sprite_.getLocalBounds();
}