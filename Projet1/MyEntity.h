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
<<<<<<< HEAD
	MyEntity();
=======
	MyEntity(sf::Texture* texture,Vector2f size, sf::Vector2u imageCount, float switchTime, float speed);
>>>>>>> e39a63a7813f267956b6dd0c8b2571982ac21769
	~MyEntity();
	void setPosition(const sf::Vector2f& pos);
	void setPosition(const int& x, const int& y);
	void draw(sf::RenderTarget& target);
<<<<<<< HEAD

	//void OnUpdate();

	sf::Vector2f GetPosition() { return body.getPosition(); }
	Collider GetCollider() { return Collider(body); }
	//void updateInput(float fps, bool is2D);
=======
	void updateInput(float fps);
	Vector2f getLastPos() { return lastPos; }
	void moveOnHitBox();
	Collider* hitbox ;
	void move(float dx, float dy) { body->setPosition(Vector2f(dx, dy)); }

	sf::Vector2f GetPosition() { return body->getPosition(); }
	RectangleShape* GetCollider() { return body; }
	void updateInput(float fps, bool is2D);
>>>>>>> e39a63a7813f267956b6dd0c8b2571982ac21769
private:
	sf::RectangleShape* body;
	sf::Transformable myTransform;
	sf::Sprite mySprite;
	sf::Texture* myTexture;
	sf::IntRect uvReckt;
	float speed;
	//Animation animation;
	int row;
	Vector2f lastPos;
};

