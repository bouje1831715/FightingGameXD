#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "./Manager/StateManager.h"
#include "./Manager/AssetManager.h"

struct Coord {
	int x;
	int y;
};

struct Spritesheet {
	sf::Texture* texture;
	int nbRows;
	int nbColums;
};

class Animation
{
public:
	Animation(Spritesheet ss, vector<Coord> indexes, vector<int> showTimes, bool loop = true);
	~Animation();
	void Update();
	Sprite* GetSprite(bool reverse = false);
	void Reset();

private:
	int currentFrame;
	float currentTime;

	sf::Sprite* currentSprite;
	sf::IntRect uvRect;

	Spritesheet spritesheet;
	vector<Coord> indexes;
	vector<int> showTimes;

	int spriteWidth;
	int spriteHeight;
};

