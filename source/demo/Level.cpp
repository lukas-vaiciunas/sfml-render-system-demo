#include "Level.h"
#include "Constants.h"
#include <fstream>

Level::Level() :
	WorldDrawable(),
	tiles_(),
	size_()
{}

void Level::load(const std::string &levelFilePath)
{
	std::ifstream in(levelFilePath);

	if (!in.is_open())
	{
		fprintf(stderr, "Failed to open \"%s\" in Level::load!\n", levelFilePath.c_str());
		return;
	}

	int numCols;
	int numRows;

	in >> numCols >> numRows;

	for (int row = 0; row < numRows; ++row)
	{
		for (int col = 0; col < numCols; ++col)
		{
			int tileTextureId;

			in >> tileTextureId;

			if (tileTextureId == 0)
			{
				continue;
			}

			tiles_.push_back(
				Tile(
					sf::Vector2f(
						static_cast<float>(col * Constants::tileSize),
						static_cast<float>(row * Constants::tileSize)),
					tileTextureId));
		}
	}

	size_.x = numCols * Constants::tileSize;
	size_.y = numRows * Constants::tileSize;

	in.close();
}

void Level::draw(
	sf::RenderTarget &target,
	sf::RenderStates states,
	const sf::Vector2f &cameraPosition) const
{
	for (const Tile &tile : tiles_)
	{
		tile.draw(target, states, cameraPosition);
	}
}

const sf::Vector2u &Level::getSize() const
{
	return size_;
}