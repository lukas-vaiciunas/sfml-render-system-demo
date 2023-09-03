#include "InterfaceSprite.h"
#include "Config.h"
#include <SFML/Graphics/RenderTarget.hpp>

InterfaceSprite::InterfaceSprite(TextureId textureId) :
	GameSprite(textureId),
	InterfaceDrawable()
{}

void InterfaceSprite::draw(
	sf::RenderTarget &target,
	sf::RenderStates states) const
{
	states.transform.scale(
		sf::Vector2f(
			Config::Interface::scale,
			Config::Interface::scale));

	target.draw(sprite_, states);
}