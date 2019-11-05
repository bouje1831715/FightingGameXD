#include "Animation.h"
#include "TimeManager.h"
#include <math.h>

Animation::Animation(Tileset ts, vector<Coord> indexes, vector<int> showTimes, bool loop)
{
	this->indexes = indexes;
	currentFrame = 0;
	currentTime = 0;

	if (size(indexes) > size(showTimes))
		this->showTimes = { -1 };
	else 
		this->showTimes = showTimes;

	if (!loop)
		this->showTimes[size(showTimes) - 1] = -1;

	currentSprite = new Sprite();
	currentSprite->setTexture(*ts.texture);
	uvReckt.width = (int)floor((ts.texture->getSize().x / float(ts.nbColums)));
	uvReckt.height = (int)floor((ts.texture->getSize().y / float(ts.nbRows)));
	
}

Animation::~Animation()
{
	delete ts.texture;
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

			uvReckt.left = indexes[currentFrame].x * uvReckt.width;
			uvReckt.top = indexes[currentFrame].y * uvReckt.height;
			currentSprite->setTextureRect(uvReckt);
		}
	}
}

Sprite* Animation::GetSprite()
{
	return currentSprite;
}
