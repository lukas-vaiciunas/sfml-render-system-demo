#pragma once

#include "GameText.h"
#include "WorldDrawable.h"

class WorldText :
	public GameText,
	public WorldDrawable
{
public:
	WorldText();

	void draw(
		sf::RenderTarget &target,
		sf::RenderStates states,
		const sf::Vector2f &cameraPosition) const override;

	void setWorldPosition(const sf::Vector2f &position);
};