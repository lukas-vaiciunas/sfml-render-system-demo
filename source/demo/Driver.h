#pragma once

#include "Level.h"
#include "Player.h"
#include "WorldCamera.h"
#include "HealthInterface.h"
#include "ControlInterface.h"

class Driver : public sf::Drawable
{
public:
	Driver();

	void update(float deltaTime);
	void updateOnKeyPress(sf::Keyboard::Key key);
	void updateOnKeyRelease(sf::Keyboard::Key key);

	void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

	bool isDone() const;
private:
	Level level_;
	Player player_;
	WorldCamera camera_;

	HealthInterface healthInterface_;
	ControlInterface moveControlInterface_;
	ControlInterface cameraControlInterface_;
	ControlInterface exitControlInterface_;

	bool isCameraFrozen_;
	bool isDone_;

	void toggleCameraFreeze_();
};