#pragma once
#include <string>
	
#include "./Manager/StateManager.h"
#include "./Manager/InputManager.h"
#include "./Manager/AssetManager.h"
#include "Level.h"
#include "MyEntity.h"
#include "Platform.h"

using namespace sf;

namespace GameView
{
	struct GameData
	{
		StateManager stateManager;
		sf::RenderWindow window;
		AssetManager assetManager;
		InputManager inputManager;
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
		const float dt = 1.0f / 60;
		Clock clock;
		const unsigned int FPS = 60;
		
		GameDataRef data = std::make_shared<GameData>();
		Platform* test;

		MyEntity* myEntity;
		Texture myTexture;


	};
}
