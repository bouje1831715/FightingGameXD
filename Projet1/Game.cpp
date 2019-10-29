#include "Game.h"

namespace GameView
{
	Game::Game(int width, int height, string titleScreen)
	{
		data->window.setVerticalSyncEnabled(true);
		data->window.create(VideoMode(width, height), titleScreen, Style::Close | Style::Titlebar);
		myTexture.loadFromFile("Image/Capture.png");
		test = new Platform(&myTexture, Vector2f(100.0f, 30.0f), Vector2f(200.0f, 150.0f));
		myEntity = new MyEntity(&myTexture,sf::Vector2f(20.0f,45.0f), sf::Vector2u(3, 2), 0.001f, 0.1f);
	}

	Game::~Game()
	{
	}

	void Game::init()
	{
		data->window.setFramerateLimit(FPS);
	}

	void Game::updateEvent()
	{
		Event event;
		// passe tous les events avant de continuer 
		while (data->window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				data->window.close();
			
			
			data->inputManager.update(event);
			myEntity->updateInput((float)FPS);
		}
	}

	void Game::updateLogic()
	{
		if (test->hitbox->checkCollision(myEntity->GetCollider(), 1.0f))
			myEntity->moveOnHitBox();
	}
	void Game::update()
	{
		//float currentTime = 0, frameTime = 0.0, interpolation =0.0f;
		while (data->window.isOpen())
		{
			Time elapsed = clock.restart();

			updateEvent();
			updateLogic();
			render();
		}
	}

	void Game::startGame()
	{
		update();
	}

	void Game::render()
	{
		data->window.clear(Color::Black);

		myEntity->draw(data->window);
		test->Draw(data->window);

		data->window.display();
	}
}