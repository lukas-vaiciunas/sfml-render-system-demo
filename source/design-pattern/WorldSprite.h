#pragma once

#include "GameSprite.h"
#include "WorldDrawable.h"

class WorldSprite :
	public GameSprite,
	public WorldDrawable
{
public:
	WorldSprite(TextureId textureId);

	void draw(
		sf::RenderTarget &target,
		sf::RenderStates states,
		const sf::Vector2f &cameraPosition) const override;
};