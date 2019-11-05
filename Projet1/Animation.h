#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "./Manager/StateManager.h"
#include "./Manager/AssetManager.h"

struct Coord {
	int x;
	int y;
};

struct Tileset {
	sf::Texture* texture;
	int nbRows;
	int nbColums;
};

class Animation
{
public:
	Animation(Tileset ts, vector<Coord> indexes, vector<int> showTimes, bool loop = true);
	~Animation();
	void Update();
	Sprite* GetSprite();

private:
	int currentFrame;
	float currentTime;

	sf::Sprite* currentSprite;
	sf::IntRect uvReckt;

	Tileset ts;
	vector<Coord> indexes;
	vector<int> showTimes;
};

