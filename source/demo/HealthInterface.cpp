#include "HealthInterface.h"
#include "FontData.h"
#include "Config.h"

HealthInterface::HealthInterface(const sf::Vector2f &interfacePosition) :
	InterfaceDrawable(),
	sprite_(21),
	text_()
{
	const sf::FloatRect spriteLocalBounds = sprite_.getLocalBounds();

	sprite_.setPosition(interfacePosition);

	text_.setFont(FontData::getInstance().getFont());
	text_.setCharacterSize(Config::Text::CharacterSize::medium);
	text_.setString("X 3");
	text_.setFillColor(sf::Color(236, 236, 236));
	text_.setOutlineColor(sf::Color(0, 0, 0));
	text_.setOutlineThickness(text_.getCharacterSize() * Config::Text::outlineScale);
	text_.setInterfacePosition(
		sf::Vector2f(
			interfacePosition.x + spriteLocalBounds.width + 1.0f,
			interfacePosition.y + spriteLocalBounds.height * 0.5f));

	const sf::FloatRect textLocalBounds = text_.getLocalBounds();

	text_.setOrigin(
		sf::Vector2f(
			textLocalBounds.left,
			textLocalBounds.top + textLocalBounds.height * 0.5f));
}

void HealthInterface::draw(
	sf::RenderTarget &target,
	sf::RenderStates states) const
{
	sprite_.draw(target, states);
	text_.draw(target, states);
}