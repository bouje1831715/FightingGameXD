#include "AssetManager.h"


namespace GameView
{
	AssetManager::AssetManager(){}
	AssetManager::~AssetManager(){}

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
