#include "TimeManager.h"

float TimeManager::DeltaTime = 0;

TimeManager::TimeManager()
{

}


TimeManager::~TimeManager()
{
}

void TimeManager::Update() 
{
	DeltaTime = (restart()).asSeconds();
}
