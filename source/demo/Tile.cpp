#include "Tile.h"

Tile::Tile(const sf::Vector2f &position, TextureId textureId) :
	WorldDrawable(),
	sprite_(textureId)
{
	sprite_.setPosition(position);
}

void Tile::draw(
	sf::RenderTarget &target,
	sf::RenderStates states,
	const sf::Vector2f &cameraPosition) const
{
	sprite_.draw(target, states, cameraPosition);
}