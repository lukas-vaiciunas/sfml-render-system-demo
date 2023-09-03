#pragma once

#include "Tile.h"
#include <string>
#include <vector>

class Level : public WorldDrawable
{
public:
	Level();

	void load(const std::string &levelFilePath);

	void draw(
		sf::RenderTarget &target,
		sf::RenderStates states,
		const sf::Vector2f &cameraPosition) const override;

	const sf::Vector2u &getSize() const;
private:
	std::vector<Tile> tiles_;
	sf::Vector2u size_;
};