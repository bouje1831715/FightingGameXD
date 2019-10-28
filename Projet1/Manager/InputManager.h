#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>

using namespace sf;

namespace GameView
{
	class InputManager
	{
	public:
		InputManager();
		~InputManager();

		bool isSpriteClicked(Sprite object, Mouse::Button button, RenderWindow &window);

		void update(const Event& eventInfo);

		Vector2i getMousePos(RenderWindow &window);
	};
}
