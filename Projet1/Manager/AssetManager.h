#pragma once
#include <map>
#include <SFML/Graphics.hpp>
#include <string>

using namespace std;
using namespace sf;

enum LevelInfo
{
	levelIntro = 0
};

namespace GameView
{
	struct TextureInfo
	{
		string path;
		string name;
		Vector2i size;
		Vector2i pos;
	};

	class AssetManager
	{
	public:
		AssetManager();
		~AssetManager();

		void loadFromLevel(LevelInfo levelInfo);

		void loadTexture(string name, string fileName);
		void loadTexture(string name, string fileName, Vector2i size, Vector2i pos);
		sf::Texture &getTexture(string name);

		void loadFont(string name, string fileName);
		sf::Font &getFont(string name);

	private:
		map<string,Texture> textureInfo;
		map<string,Font> fontInfo;
	};
}