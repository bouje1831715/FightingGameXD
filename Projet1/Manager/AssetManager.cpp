#include "AssetManager.h"
#include <iostream>


namespace GameView
{
	AssetManager::AssetManager() 
	{

	}
	AssetManager::~AssetManager(){}

	void AssetManager::loadFromLevel(LevelInfo levelInfo)
	{
		string fileName = getNameFile(levelInfo);
		string levelLoader = "";
		try
		{
			fileStream.open("test.txt");
		}
		catch (const std::exception& e)
		{
			std::cout << e.what();
		}
		if( !fileStream.bad() )
		{
			levelLoader = readFromLoadedFile();
		}
		
		 
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

	string AssetManager::getNameFile(LevelInfo levelInfo)
	{
		string fileName = "";

		switch (levelInfo)
		{
			case LevelInfo::levelIntro: fileName = "levelIntro.txt"; break;
		}
		return fileName;
	}

	string AssetManager::readFromLoadedFile()
	{
		string inputFile = "";
		string line = "";

		if (fileStream.is_open())
		{
			while (getline(fileStream, line))
			{
				inputFile.append(line);
			}
			fileStream.close();
		}
		return inputFile;
	}
}
