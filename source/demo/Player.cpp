#include "Player.h"
#include "FontData.h"
#include "Config.h"

Player::Player(float maxSpeed, TextureId textureId) :
	WorldDrawable(),
	moveFlags_(MoveFlags::None),
	sprite_(textureId),
	text_(),
	position_(),
	size_(0.0f, 0.0f),
	velocity_(0.0f, 0.0f),
	maxSpeed_(maxSpeed)
{
	text_.setFont(FontData::getInstance().getFont());
	text_.setString("Player");
	text_.setCharacterSize(Config::Text::CharacterSize::medium);
	text_.setFillColor(sf::Color(236, 236, 236));
	text_.setOutlineColor(sf::Color(0, 0, 0));
	text_.setOutlineThickness(text_.getCharacterSize() * Config::Text::outlineScale);

	const sf::FloatRect textLocalBounds = text_.getLocalBounds();

	text_.setOrigin(
		sf::Vector2f(
			textLocalBounds.left + textLocalBounds.width * 0.5f,
			textLocalBounds.top + textLocalBounds.height * 0.5f));

	const sf::FloatRect spriteLocalBounds = sprite_.getLocalBounds();

	size_.x = spriteLocalBounds.width;
	size_.y = spriteLocalBounds.height;
}

void Player::update(float deltaTime)
{
	this->updateVelocity_();
	this->updatePosition_(deltaTime);
}

void Player::updateOnKeyPress(sf::Keyboard::Key key)
{
	switch (key)
	{
		case sf::Keyboard::Key::W:
		case sf::Keyboard::Key::Up:
			moveFlags_ |= MoveFlags::Up;
			break;
		case sf::Keyboard::Key::A:
		case sf::Keyboard::Key::Left:
			moveFlags_ |= MoveFlags::Left;
			break;
		case sf::Keyboard::Key::S:
		case sf::Keyboard::Key::Down:
			moveFlags_ |= MoveFlags::Down;
			break;
		case sf::Keyboard::Key::D:
		case sf::Keyboard::Key::Right:
			moveFlags_ |= MoveFlags::Right;
			break;
	}
}

void Player::updateOnKeyRelease(sf::Keyboard::Key key)
{
	switch (key)
	{
		case sf::Keyboard::Key::W:
		case sf::Keyboard::Key::Up:
			moveFlags_ &= ~MoveFlags::Up;
			break;
		case sf::Keyboard::Key::A:
		case sf::Keyboard::Key::Left:
			moveFlags_ &= ~MoveFlags::Left;
			break;
		case sf::Keyboard::Key::S:
		case sf::Keyboard::Key::Down:
			moveFlags_ &= ~MoveFlags::Down;
			break;
		case sf::Keyboard::Key::D:
		case sf::Keyboard::Key::Right:
			moveFlags_ &= ~MoveFlags::Right;
			break;
	}
}

void Player::draw(
	sf::RenderTarget &target,
	sf::RenderStates states,
	const sf::Vector2f &cameraPosition) const
{
	sprite_.draw(target, states, cameraPosition);
	text_.draw(target, states, cameraPosition);
}

void Player::setPosition(const sf::Vector2f &position)
{
	position_ = position;

	text_.setWorldPosition(
		sf::Vector2f(
			position_.x + size_.x * 0.5f,
			position_.y - 3.0f));

	sprite_.setPosition(position_);
}

const sf::Vector2f &Player::getPosition() const
{
	return position_;
}

const sf::Vector2f &Player::getSize() const
{
	return size_;
}

void Player::updatePosition_(float deltaTime)
{
	this->setPosition(position_ + velocity_ * deltaTime);
}

void Player::updateVelocity_()
{
	velocity_.x = 0.0f;
	velocity_.y = 0.0f;

	if (moveFlags_ == MoveFlags::None)
	{
		return;
	}

	if (moveFlags_ & MoveFlags::Up)
	{
		velocity_.y -= maxSpeed_;
	}
	if (moveFlags_ & MoveFlags::Down)
	{
		velocity_.y += maxSpeed_;
	}
	if (moveFlags_ & MoveFlags::Left)
	{
		velocity_.x -= maxSpeed_;
	}
	if (moveFlags_ & MoveFlags::Right)
	{
		velocity_.x += maxSpeed_;
	}

	if (velocity_.x == 0.0f && velocity_.y == 0.0f)
	{
		return;
	}

	float speed = sqrtf(velocity_.x * velocity_.x + velocity_.y * velocity_.y);

	if (speed > maxSpeed_)
	{
		velocity_ = velocity_ / speed * maxSpeed_;
	}
}