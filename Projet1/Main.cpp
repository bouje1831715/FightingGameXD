#include <SFML/Graphics.hpp>
#include "Game.h"

using namespace sf;
using namespace GameView;

int main()
{
	string egineName = "My game";
	Game myEngine(800,600,egineName);
	myEngine.init();
	myEngine.startGame();

	return EXIT_SUCCESS;
}
