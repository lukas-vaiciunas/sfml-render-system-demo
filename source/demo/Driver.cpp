#include "Driver.h"
#include "Config.h"

Driver::Driver() :
	sf::Drawable(),
	level_(),
	player_(48.0f, 1),
	camera_(),
	healthInterface_(
		sf::Vector2f(4.0f, 4.0f)),
	moveControlInterface_(
		sf::Vector2f(4.0f, Config::Window::height / Config::Interface::scale - 17.0f),
		"[WASD]",
		"Move"),
	cameraControlInterface_(
		sf::Vector2f(4.0f, Config::Window::height / Config::Interface::scale - 12.0f),
		"[SPACE]",
		"Freeze Camera"),
	exitControlInterface_(
		sf::Vector2f(4.0f, Config::Window::height / Config::Interface::scale - 7.0f),
		"[ESC]",
		"Exit Demo"),
	isCameraFrozen_(false),
	isDone_(false)
{
	level_.load("./data/level.txt");

	player_.setPosition((sf::Vector2f(level_.getSize()) - player_.getSize()) * 0.5f);
	camera_.center(player_.getPosition() + player_.getSize() * 0.5f);
}

void Driver::update(float deltaTime)
{
	player_.update(deltaTime);

	if (!isCameraFrozen_)
	{
		camera_.center(player_.getPosition() + player_.getSize() * 0.5f);
	}
}

void Driver::updateOnKeyPress(sf::Keyboard::Key key)
{
	if (key == sf::Keyboard::Key::Space)
	{
		this->toggleCameraFreeze_();
	}
	else if (key == sf::Keyboard::Key::Escape)
	{
		isDone_ = true;
	}
	else
	{
		player_.updateOnKeyPress(key);
	}
}

void Driver::updateOnKeyRelease(sf::Keyboard::Key key)
{
	player_.updateOnKeyRelease(key);
}

void Driver::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	const sf::Vector2f &cameraPosition = camera_.getPosition();

	level_.draw(target, states, cameraPosition);
	player_.draw(target, states, cameraPosition);

	healthInterface_.draw(target, states);
	moveControlInterface_.draw(target, states);
	cameraControlInterface_.draw(target, states);
	exitControlInterface_.draw(target, states);
}

bool Driver::isDone() const
{
	return isDone_;
}

void Driver::toggleCameraFreeze_()
{
	isCameraFrozen_ = !isCameraFrozen_;

	cameraControlInterface_.setActionString(
		isCameraFrozen_ ? "Unfreeze Camera" : "Freeze Camera");
}