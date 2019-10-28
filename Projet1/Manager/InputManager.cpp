#include "InputManager.h"


namespace GameView
{
	InputManager::InputManager(){}
	InputManager::~InputManager(){}

	bool InputManager::isSpriteClicked(Sprite object, Mouse::Button button, RenderWindow &window)
	{
		if (Mouse::isButtonPressed(button))
		{
			// create a temp rect to check the collision
			
			IntRect collisionRect((int)object.getPosition().x, (int)object.getPosition().y,
				(int)object.getGlobalBounds().width, (int)object.getGlobalBounds().height);

			if (collisionRect.contains(Mouse::getPosition(window)))
				return true;
		}
		return false;
	}

	void InputManager::update(const Event& eventInfo)
	{
		switch(eventInfo.key.code)
		{
			case Keyboard::W :
			case Keyboard::Up:

			break;

			case Keyboard::A:
			case Keyboard::Left:

			break;

			case Keyboard::D:
			case Keyboard::Right:

			break;

			case Keyboard::S:
			case Keyboard::Down:

			break;

			default: break;
		}
	}

	Vector2i InputManager::getMousePos(RenderWindow &window)
	{
		return Mouse::getPosition(window);
	}
}