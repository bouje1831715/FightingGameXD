#include "AssetManager.h"


namespace GameView
{
	AssetManager::AssetManager() 
	{

	}
	AssetManager::~AssetManager(){}

	void AssetManager::loadFromLevel(LevelInfo levelInfo)
	{
		/* test 1-2 test/
		need to load from a file ( or all load before game is launch )
		Exemple d'utilisation
		TextureInfo textInfo;
		textInfo.name = "test";
		textInfo.path = "Image/boss.png";
		textInfo.size = Vector2i(946, 416);
		textInfo.pos = Vector2i(0, 0);

		loadTexture(textInfo.name, textInfo.path, textInfo.size, textInfo.pos);
		*/

		//WIP 
		switch (levelInfo)
		{
			case LevelInfo::levelIntro:
			break;
		}
	}

	void AssetManager::loadTexture(string name, string fileName)
	{
		Texture texture;

		if (texture.loadFromFile(fileName))
		{
			textureInfo[name] = texture;
		}	
	}

	Texture &AssetManager::getTexture(string name)
	{
		return textureInfo.at(name);
	}

	void AssetManager::loadFont(string name, string fileName)
	{
		Font font;

		if (font.loadFromFile(fileName))
		{
			fontInfo[name] = font;
		}
	}

	Font &AssetManager::getFont(string name)
	{
		return fontInfo.at(name);
	}

}
