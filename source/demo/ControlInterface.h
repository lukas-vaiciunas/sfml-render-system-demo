#pragma once

#include "InterfaceText.h"

class ControlInterface : public InterfaceDrawable
{
public:
	ControlInterface(
		const sf::Vector2f &interfacePosition,
		const sf::String &keyString,
		const sf::String &actionString);

	void draw(
		sf::RenderTarget &target,
		sf::RenderStates states) const override;

	void setActionString(const sf::String &string);
private:
	InterfaceText keyText_;
	InterfaceText actionText_;
};