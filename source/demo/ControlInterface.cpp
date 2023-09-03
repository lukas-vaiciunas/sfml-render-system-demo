#include "ControlInterface.h"
#include "FontData.h"
#include "Config.h"

ControlInterface::ControlInterface(
	const sf::Vector2f &interfacePosition,
	const sf::String &keyString,
	const sf::String &actionString)
	:
	InterfaceDrawable(),
	keyText_(),
	actionText_()
{
	const sf::Font &font = FontData::getInstance().getFont();

	keyText_.setFont(font);
	keyText_.setCharacterSize(Config::Text::CharacterSize::medium);
	keyText_.setString(keyString);
	keyText_.setFillColor(sf::Color(236, 236, 236));
	keyText_.setOutlineColor(sf::Color(0, 0, 0));
	keyText_.setOutlineThickness(keyText_.getCharacterSize() * Config::Text::outlineScale);
	keyText_.setInterfacePosition(interfacePosition);

	const sf::FloatRect keyTextLocalBounds = keyText_.getLocalBounds();

	keyText_.setOrigin(
		sf::Vector2f(
			keyTextLocalBounds.left,
			keyTextLocalBounds.top));

	actionText_.setFont(font);
	actionText_.setCharacterSize(Config::Text::CharacterSize::medium);
	actionText_.setFillColor(sf::Color(236, 236, 236));
	actionText_.setOutlineColor(sf::Color(0, 0, 0));
	actionText_.setOutlineThickness(actionText_.getCharacterSize() * Config::Text::outlineScale);
	actionText_.setInterfacePosition(
		sf::Vector2f(
			interfacePosition.x + 16.0f,
			interfacePosition.y));

	this->setActionString(actionString);
}

void ControlInterface::draw(
	sf::RenderTarget &target,
	sf::RenderStates states) const
{
	keyText_.draw(target, states);
	actionText_.draw(target, states);
}

void ControlInterface::setActionString(const sf::String &string)
{
	actionText_.setString(string);

	const sf::FloatRect textLocalBounds = actionText_.getLocalBounds();

	actionText_.setOrigin(
		sf::Vector2f(
			textLocalBounds.left,
			textLocalBounds.top));
}