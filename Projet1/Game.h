#pragma once
#include <string>
#include "./Manager/StateManager.h"
#include "./Manager/AssetManager.h"
#include "InputManager.h"
#include "Level.h"
#include "Entity.h"
#include "Platform.h"
#include "TimeManager.h"

using namespace sf;

namespace GameView
{
	struct GameData
	{
		StateManager stateManager;
		sf::RenderWindow window;
		AssetManager assetManager;
	};

	typedef std::shared_ptr<GameData> GameDataRef;

	class Game
	{
	public:
		Game(int width, int height, string titleScreen);
		~Game();

		void init();
		void startGame();

	private:
		void update();
		void updateInput();
		void updateLogic();
		void render();
		void updateEvent();
<<<<<<< HEAD

		TimeManager timeManager;
=======
		const float dt = 1.0f / 60;
		Clock clock;
>>>>>>> e39a63a7813f267956b6dd0c8b2571982ac21769
		const unsigned int FPS = 60;
		
		GameDataRef data = std::make_shared<GameData>();
		Platform* test;

		vector<Entity*> entities;
		Texture myTexture;
	};
}
