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
	MyEntity(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
	~MyEntity();
	void setPosition(const sf::Vector2f& pos);
	void setPosition(const int& x, const int& y);
	void draw(sf::RenderTarget& target);
	void updateInput(float fps);

	sf::Vector2f GetPosition() { return body.getPosition(); }
	Collider GetCollider() { return Collider(body); }
	void updateInput(float fps, bool is2D);
private:
	sf::RectangleShape body;
	sf::Transformable myTransform;
	sf::Sprite mySprite;
	sf::Texture* myTexture;
	sf::IntRect uvReckt;
	float speed;
	Animation animation;
	int row;
};

