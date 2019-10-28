#pragma once

namespace GameView
{
	class State
	{
	public:
		virtual void init() = 0;

		virtual	void handleInput() = 0;
		virtual void update() = 0;
		virtual void draw(float deltaTime) = 0;

		virtual void pause() {}
		virtual void resume() {}

		State();
		~State();
	};
}