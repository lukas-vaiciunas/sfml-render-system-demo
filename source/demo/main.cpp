#include "Driver.h"
#include "Config.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

int main(void)
{
#ifdef _DEBUG
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

	const sf::Color clearColor(116, 180, 116);

	sf::RenderWindow window(
		sf::VideoMode(
			Config::Window::width,
			Config::Window::height,
			Config::Window::bitsPerPixel),
		"SFML Render System Demo",
		sf::Style::Titlebar | sf::Style::Close);

	window.setFramerateLimit(60);
	window.setKeyRepeatEnabled(false);

	sf::Clock frameClock;
	float deltaTime = 0.0f;

	Driver driver;

	while (window.isOpen()
		&& !driver.isDone())
	{
		sf::Event ev;

		while (window.pollEvent(ev))
		{
			switch (ev.type)
			{
				case sf::Event::KeyPressed:
					driver.updateOnKeyPress(ev.key.code);
					break;
				case sf::Event::KeyReleased:
					driver.updateOnKeyRelease(ev.key.code);
					break;
				case sf::Event::Closed:
					window.close();
					break;
			}
		}

		deltaTime = frameClock.restart().asSeconds();

		driver.update(deltaTime);

		window.clear(clearColor);
		window.draw(driver);
		window.display();
	}

	return 0;
}