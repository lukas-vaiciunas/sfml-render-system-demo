#pragma once

#include "GameSprite.h"
#include "InterfaceDrawable.h"

class InterfaceSprite :
	public GameSprite,
	public InterfaceDrawable
{
public:
	InterfaceSprite(TextureId textureId);

	void draw(
		sf::RenderTarget &target,
		sf::RenderStates states) const override;
};