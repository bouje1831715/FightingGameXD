#include "Entity.h"
#include "TimeManager.h"
#include "Monk.h"
#include "Action.h"
#include "PlayerStanding.h"

Entity::Entity()
{
	body = new RectangleShape();
	CurrentAction = new Action();
}


Entity::~Entity()
{
	delete body;
}

void Entity::setPosition(const sf::Vector2f& pos)
{
	position.setPosition(pos.x, pos.y);
}
void Entity::setPosition(const int& x, const int& y)
{
	position.setPosition((float)x, (float)y);
}

void Entity::Update()
{

	int i = (CurrentAction)->Update();
	if (i != -1)
		(this)->ChangeAction(i);
}

void Entity::Draw(sf::RenderTarget& target)
{
	animator.Update();
	Sprite* s = animator.GetSprite();
	target.draw(*s, position.getTransform());
}

void Entity::MoveOnHitBox()
{
	setPosition(body->getPosition());
}