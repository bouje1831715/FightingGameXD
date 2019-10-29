#pragma once
#include <SFML\Graphics\Transformable.hpp>
#include <SFML\Graphics\Drawable.hpp>
#include <SFML\Graphics\Sprite.hpp>
#include <SFML\Graphics\Texture.hpp>
#include <SFML\Graphics.hpp>
#include "Collider.h"
#include "Animation.h"
class MyEntity:public sf::Transformable
{
public:
	MyEntity(sf::Texture* texture,Vector2f size, sf::Vector2u imageCount, float switchTime, float speed);
	~MyEntity();
	void setPosition(const sf::Vector2f& pos);
	void setPosition(const int& x, const int& y);
	void draw(sf::RenderTarget& target);
	void updateInput(float fps);
	Vector2f getLastPos() { return lastPos; }
	void moveOnHitBox();
	Collider* hitbox ;
	void move(float dx, float dy) { body->setPosition(Vector2f(dx, dy)); }

	sf::Vector2f GetPosition() { return body->getPosition(); }
	RectangleShape* GetCollider() { return body; }
	void updateInput(float fps, bool is2D);
private:
	sf::RectangleShape* body;
	sf::Transformable myTransform;
	sf::Sprite mySprite;
	sf::Texture* myTexture;
	sf::IntRect uvReckt;
	float speed;
	Animation animation;
	int row;
	Vector2f lastPos;
};

