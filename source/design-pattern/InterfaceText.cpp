#include "InterfaceText.h"
#include "Config.h"
#include <SFML/Graphics/RenderTarget.hpp>

InterfaceText::InterfaceText() :
	GameText(),
	InterfaceDrawable()
{}

void InterfaceText::draw(
	sf::RenderTarget &target,
	sf::RenderStates states) const
{
	target.draw(text_, states);
}

void InterfaceText::setInterfacePosition(const sf::Vector2f &position)
{
	this->setPosition(position * Config::Interface::scale);
}