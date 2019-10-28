#pragma once
#include <map>
#include <SFML/Graphics.hpp>
#include <string>

using namespace std;
using namespace sf;

namespace GameView
{
	class AssetManager
	{
	public:
		AssetManager();
		~AssetManager();

		void loadTexture(string name, string fileName);
		sf::Texture &getTexture(string name);

		void loadFont(string name, string fileName);
		sf::Font &getFont(string name);

	private:
		map<string,Texture> textureInfo;
		map<string,Font> fontInfo;
	};
}