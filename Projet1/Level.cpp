#include "Level.h"

namespace GameView
{

	Level::Level():layerSize(3)
	{
		currentPos = Vector2i(0, 0);
	}


	Level::~Level()
	{
	}
	
	void Level::init()
	{

	}

	void Level::drawBackGround(sf::RenderTarget& target)
	{
		vector<sf::Sprite>::iterator it;
		for (it = backGround.begin(); it != backGround.end(); it++)
		{
			target.draw((*it));
		}

	}
	void Level::drawPlayGround(sf::RenderTarget& target)
	{
		//need to see if we always draw all the map or just a part of it( with view settings )
	  /*for (int i = 0; i < playGround.size(); i++)
		{
			for (int j = 0; j < playGround[i].size(); j++)
			{
				for (int k = 0; k < layerSize; k++)
				{
					target.draw(playGround[i][j][k]);
				}
			}
		}*/
	}
}
