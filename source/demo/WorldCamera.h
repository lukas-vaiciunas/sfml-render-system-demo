#pragma once

#include <SFML/System/Vector2.hpp>

class WorldCamera
{
public:
	WorldCamera();

	void center(const sf::Vector2f &centerPosition);

	const sf::Vector2f &getPosition() const;
private:
	sf::Vector2f position_;
};