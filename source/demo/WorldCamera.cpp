#include "WorldCamera.h"
#include "Config.h"

WorldCamera::WorldCamera() :
	position_(0.0f, 0.0f)
{}

void WorldCamera::center(const sf::Vector2f &centerPosition)
{
	const float invWorldScale = 1.0f / Config::World::scale;

	const sf::Vector2f scaledWindowSize(
		Config::Window::width * invWorldScale,
		Config::Window::height * invWorldScale);

	position_ = centerPosition - scaledWindowSize * 0.5f;
}

const sf::Vector2f &WorldCamera::getPosition() const
{
	return position_;
}