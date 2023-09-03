#pragma once

namespace sf
{
	class RenderTarget;
	class RenderStates;
	template<typename T=float> class Vector2;
	typedef Vector2<float> Vector2f;
}

class WorldDrawable
{
public:
	WorldDrawable() {}
	
	virtual ~WorldDrawable() {}

	virtual void draw(
		sf::RenderTarget &target,
		sf::RenderStates states,
		const sf::Vector2f &cameraPosition) const = 0;
};