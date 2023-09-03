#pragma once

namespace sf
{
	class RenderTarget;
	class RenderStates;
}

class InterfaceDrawable
{
public:
	InterfaceDrawable() {}

	virtual ~InterfaceDrawable() {}

	virtual void draw(
		sf::RenderTarget &target,
		sf::RenderStates states) const = 0;
};