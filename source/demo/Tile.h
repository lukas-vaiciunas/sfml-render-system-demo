#pragma once

#include "WorldSprite.h"

class Tile : public WorldDrawable
{
public:
	Tile(const sf::Vector2f &position, TextureId textureId);
	
	void draw(
		sf::RenderTarget &target,
		sf::RenderStates states,
		const sf::Vector2f &cameraPosition) const override;
private:
	WorldSprite sprite_;
};