#include "WorldText.h"
#include "Config.h"
#include <SFML/Graphics/RenderTarget.hpp>

WorldText::WorldText() :
	GameText(),
	WorldDrawable()
{}

void WorldText::draw(
	sf::RenderTarget &target,
	sf::RenderStates states,
	const sf::Vector2f &cameraPosition) const
{
	states.transform.translate(-cameraPosition * Config::World::scale);

	target.draw(text_, states);
}

void WorldText::setWorldPosition(const sf::Vector2f &position)
{
	this->setPosition(position * Config::World::scale);
}