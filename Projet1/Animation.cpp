#include "Animation.h"
#include "TimeManager.h"
#include <math.h>

Animation::Animation(Spritesheet ss, vector<Coord> indexes, vector<int> showTimes, bool loop)
{
	this->indexes = indexes;
	currentFrame = 0;
	currentTime = 0;

	spritesheet = ss;


	if (size(indexes) > size(showTimes))
		this->showTimes = { -1 };
	else 
		this->showTimes = showTimes;

	if (!loop)
		this->showTimes[size(showTimes) - 1] = -1;

	currentSprite = new Sprite();
	currentSprite->setTexture(*spritesheet.texture);
	currentSprite->setScale(2, 2);
	spriteWidth = (int)floor((spritesheet.texture->getSize().x / float(spritesheet.nbColums)));
	spriteHeight = (int)floor((spritesheet.texture->getSize().y / float(spritesheet.nbRows)));
	uvRect.width = spriteWidth;
	uvRect.height = spriteHeight;
	currentSprite->setTextureRect(uvRect);
}

Animation::~Animation()
{
	//delete spritesheet.texture;
	delete currentSprite;
}

void Animation::Update()
{
	if (showTimes[currentFrame] != -1)
	{
		currentTime += TimeManager::DeltaTime;
		if (currentTime >= (float)showTimes[currentFrame]/1000)
		{
			currentTime -= (float)showTimes[currentFrame]/1000;
			currentFrame++;

			if (currentFrame >= size(indexes)) 
				currentFrame = 0;
		}
	}
}

Sprite* Animation::GetSprite(bool reverse)
{

	if (reverse)
	{
		uvRect.width = -spriteWidth;
		uvRect.left = (indexes[currentFrame].x + 1) * spriteWidth;
	}
	else
	{
		uvRect.width = spriteWidth;
		uvRect.left = indexes[currentFrame].x * spriteWidth;
	}
	uvRect.top = indexes[currentFrame].y * spriteHeight;

	currentSprite->setTextureRect(uvRect);

	return currentSprite;
}

void Animation::Reset()
{
	currentFrame = 0;
	currentTime = 0;
	uvRect.top = indexes[currentFrame].y * spriteHeight;
	currentSprite->setTextureRect(uvRect);
}
