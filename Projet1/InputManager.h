#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include <vector>

using namespace sf;
using namespace std;

enum Keys{UP, DOWN, LEFT, RIGHT, A, B, X, Y, L1, L2, L3, R1, R2, R3, START, SELECT, LEFTAXISX, LEFTAXISY, RIGHTAXISX, RIGHTAXISY};

class InputManager
{
public:
	InputManager();
	~InputManager();

	void Initiate();

	static float GetAxis(Keys K);
	static bool GetKeyState(Keys K);

private:
	static vector<Keyboard::Key> buttonUP;
	static vector<Keyboard::Key> buttonDOWN;
	static vector<Keyboard::Key> buttonLEFT;
	static vector<Keyboard::Key> buttonRIGHT;

	static vector<Keyboard::Key> buttonA;
	static vector<Keyboard::Key> buttonB;
	static vector<Keyboard::Key> buttonX;
	static vector<Keyboard::Key> buttonY;

	static vector<Keyboard::Key> buttonL1;
	static vector<Keyboard::Key> buttonL2;
	static vector<Keyboard::Key> buttonL3;
	static vector<Keyboard::Key> buttonR1;
	static vector<Keyboard::Key> buttonR2;
	static vector<Keyboard::Key> buttonR3;

	static vector<Keyboard::Key> buttonStart;
	static vector<Keyboard::Key> buttonSelect;
};

