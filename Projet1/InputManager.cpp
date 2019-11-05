#include "InputManager.h"

vector<Keyboard::Key> InputManager::buttonUP = vector<Keyboard::Key>();
vector<Keyboard::Key> InputManager::buttonDOWN = vector<Keyboard::Key>();
vector<Keyboard::Key> InputManager::buttonLEFT = vector<Keyboard::Key>();
vector<Keyboard::Key> InputManager::buttonRIGHT = vector<Keyboard::Key>();

vector<Keyboard::Key> InputManager::buttonA = vector<Keyboard::Key>();
vector<Keyboard::Key> InputManager::buttonB = vector<Keyboard::Key>();
vector<Keyboard::Key> InputManager::buttonX = vector<Keyboard::Key>();
vector<Keyboard::Key> InputManager::buttonY = vector<Keyboard::Key>();

vector<Keyboard::Key> InputManager::buttonL1 = vector<Keyboard::Key>();
vector<Keyboard::Key> InputManager::buttonL2 = vector<Keyboard::Key>();
vector<Keyboard::Key> InputManager::buttonL3 = vector<Keyboard::Key>();
vector<Keyboard::Key> InputManager::buttonR1 = vector<Keyboard::Key>();
vector<Keyboard::Key> InputManager::buttonR2 = vector<Keyboard::Key>();
vector<Keyboard::Key> InputManager::buttonR3 = vector<Keyboard::Key>();

vector<Keyboard::Key> InputManager::buttonStart = vector<Keyboard::Key>();
vector<Keyboard::Key> InputManager::buttonSelect = vector<Keyboard::Key>();

InputManager::InputManager()
{

}

InputManager::~InputManager()
{

}

void InputManager::Initiate()
{
	buttonUP.push_back(Keyboard::Up);
	buttonDOWN.push_back(Keyboard::Down);
	buttonLEFT.push_back(Keyboard::Left);
	buttonRIGHT.push_back(Keyboard::Right);

	buttonA.push_back(Keyboard::Space);
	buttonB.push_back(Keyboard::Z);
	buttonX.push_back(Keyboard::X);
	buttonY.push_back(Keyboard::C);

	buttonL1.push_back(Keyboard::A);
	buttonL2.push_back(Keyboard::Q);
	buttonL3.push_back(Keyboard::Num1);
	buttonR1.push_back(Keyboard::D);
	buttonR2.push_back(Keyboard::E);
	buttonR3.push_back(Keyboard::Num3);

	buttonStart.push_back(Keyboard::Enter);
	buttonStart.push_back(Keyboard::Escape);
	buttonSelect.push_back(Keyboard::BackSpace);
}

float InputManager::GetAxis(Keys K)
{
	//TODO
	/*switch (K) 
	{

	}*/
	return 1.0f;
}

bool InputManager::GetKeyState(Keys K)
{
	vector<Keyboard::Key> validKeys;
	switch (K)
	{
	case UP:
		validKeys = buttonUP;
		break;
	case DOWN:
		validKeys = buttonDOWN;
		break;
	case LEFT:
		validKeys = buttonLEFT;
		break;
	case RIGHT:
		validKeys = buttonRIGHT;
		break;

	case A:
		validKeys = buttonA;
		break;
	case B:
		validKeys = buttonB;
		break;
	case X:
		validKeys = buttonX;
		break;
	case Y:
		validKeys = buttonY;
		break;

	case L1:
		validKeys = buttonL1;
		break;
	case L2:
		validKeys = buttonL2;
		break;
	case L3:
		validKeys = buttonL3;
		break;
	case R1:
		validKeys = buttonR1;
		break;
	case R2:
		validKeys = buttonR2;
		break;
	case R3:
		validKeys = buttonR3;
		break;

	case START:
		validKeys = buttonStart;
		break;
	case SELECT:
		validKeys = buttonR1;
		validKeys = buttonSelect;
		break;
	}
	bool toReturn = false;
	for (Keyboard::Key k2 : validKeys)
		if (Keyboard::isKeyPressed(k2))
			toReturn = true;
	return toReturn;
}
