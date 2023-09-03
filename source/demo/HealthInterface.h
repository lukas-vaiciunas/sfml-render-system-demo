#pragma once

#include "InterfaceSprite.h"
#include "InterfaceText.h"

class HealthInterface : public InterfaceDrawable
{
public:
	HealthInterface(const sf::Vector2f &interfacePosition);

	void draw(
		sf::RenderTarget &target,
		sf::RenderStates states) const override;
private:
	InterfaceSprite sprite_;
	InterfaceText text_;
};