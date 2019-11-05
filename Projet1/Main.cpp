#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Manager/AssetManager.h"
#include "LevelLoader.h"

using namespace sf;
using namespace GameView;

int main()
{
	string egineName = "My game";
	Game myEngine(800,600,egineName);

	LevelLoader loader;
	vector<vector<vector<TileIdentity>>> levelInfo = loader.LoadFromFile("Level/Church_for_test.lvl");
	

	AssetManager managerTest;
	managerTest.loadFromLevel(LevelInfo::levelIntro);



	myEngine.init();
	myEngine.startGame();

	return EXIT_SUCCESS;
}
