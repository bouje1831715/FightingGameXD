#pragma once
#include <SFML\Graphics\Transformable.hpp>
#include <SFML\Graphics\Drawable.hpp>
#include <SFML\Graphics\Sprite.hpp>
#include "Animation.h"
#include "Animator.h"
#include "Action.h"

class Entity :
	public sf::Transformable
{
public:
	Entity();
	~Entity();

	void setPosition(const sf::Vector2f& pos);
	void setPosition(const int& x, const int& y);

	virtual void ChangeAction(int enumPlaceholder) = 0;
	void Update();
	void Draw(sf::RenderTarget& target);

protected:
	Animator animator;
	sf::Transformable position;
	Action& CurrentAction = Action();
};

