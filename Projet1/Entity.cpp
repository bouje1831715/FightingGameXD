#include "Entity.h"
#include "TimeManager.h"

Entity::Entity()
{
}


Entity::~Entity()
{

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

	int i = CurrentAction.Update();
	if (i != -1)
		this->ChangeAction(i);
}

void Entity::Draw(sf::RenderTarget& target)
{
	animator.Update();
	Sprite* s = animator.GetSprite();
	target.draw(*s, position.getTransform());
}