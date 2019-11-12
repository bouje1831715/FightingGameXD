#pragma once
#include "Animation.h"
#include <iostream>
#include <SFML\Graphics\Sprite.hpp>

class Animator
{
public:
	Animator();
	~Animator();

	void AddAnimation(Animation* a, string name);
	void ChangeAnimation(string name);
	Sprite* GetSprite(bool reverse = false);
	void Update();
private:
	Animation* currentAnimation;
	std::map<string, Animation*> animations;

};

