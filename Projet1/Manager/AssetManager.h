#pragma once
#include <map>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System/FileInputStream.hpp>


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

		void init();
		void loadFromLevel(LevelInfo levelInfo);

		void loadTexture(string name, string fileName);
		void loadTexture(string name, string fileName, Vector2i size, Vector2i pos);
		Texture &getTexture(string name);

		void loadFont(string name, string fileName);
		Font &getFont(string name);

	private:
		void preLoadSprite(const string& fileName);

		vector<string> tabFileToLoad;

		string getNameFile(LevelInfo levelInfo);
	

		map<string,Texture> textureInfo;
		map<string,Font> fontInfo;
	};
}