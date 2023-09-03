#include "WorldSprite.h"
#include "Config.h"
#include <SFML/Graphics/RenderTarget.hpp>

WorldSprite::WorldSprite(TextureId textureId) :
	GameSprite(textureId),
	WorldDrawable()
{}

void WorldSprite::draw(
	sf::RenderTarget &target,
	sf::RenderStates states,
	const sf::Vector2f &cameraPosition) const
{
	states.transform.scale(
		sf::Vector2f(
			Config::World::scale,
			Config::World::scale));

	states.transform.translate(-cameraPosition);

	target.draw(sprite_, states);
}