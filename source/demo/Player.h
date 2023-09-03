#pragma once

#include "WorldSprite.h"
#include "WorldText.h"
#include <SFML/Window/Keyboard.hpp>

class Player : public WorldDrawable
{
public:
	Player(float maxSpeed, TextureId textureId);

	void update(float deltaTime);
	void updateOnKeyPress(sf::Keyboard::Key key);
	void updateOnKeyRelease(sf::Keyboard::Key key);

	void draw(
		sf::RenderTarget &target,
		sf::RenderStates states,
		const sf::Vector2f &cameraPosition) const override;

	void setPosition(const sf::Vector2f &position);

	const sf::Vector2f &getPosition() const;
	const sf::Vector2f &getSize() const;
private:
	enum MoveFlags : uint8_t
	{
		None = 0,
		Up = 1,
		Down = 2,
		Left = 4,
		Right = 8
	};

	uint8_t moveFlags_;

	WorldSprite sprite_;
	WorldText text_;

	sf::Vector2f position_;
	sf::Vector2f size_;
	sf::Vector2f velocity_;

	float maxSpeed_;

	void updatePosition_(float deltaTime);
	void updateVelocity_();
};