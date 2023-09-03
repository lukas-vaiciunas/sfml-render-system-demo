#pragma once

#include "GameText.h"
#include "InterfaceDrawable.h"

class InterfaceText :
	public GameText,
	public InterfaceDrawable
{
public:
	InterfaceText();

	void draw(
		sf::RenderTarget &target,
		sf::RenderStates states) const override;

	void setInterfacePosition(const sf::Vector2f &position);
};