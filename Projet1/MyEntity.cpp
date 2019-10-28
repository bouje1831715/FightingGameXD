#include "MyEntity.h"
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML\Window\Keyboard.hpp>

MyEntity::MyEntity(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) : animation(texture,imageCount,switchTime)
{
	myTexture=texture;
	mySprite.setTexture(*myTexture);
	mySprite.setScale(.2, .2);
	this->speed = speed;
	uvReckt.left = (texture->getSize().x / float(imageCount.x));
	uvReckt.height = (texture->getSize().y / float(imageCount.y));
}


MyEntity::~MyEntity()
{
}

void MyEntity::setPosition(const sf::Vector2f& pos)
{
	myTransform.setPosition(pos.x, pos.y);
}
void MyEntity::setPosition(const int& x, const int& y)
{
	myTransform.setPosition(x, y);
}



void MyEntity::draw(sf::RenderTarget& target)
{
	target.draw(mySprite, myTransform.getTransform());
}

void MyEntity::updateInput(float fps)
{

	sf::Vector2f movements = { 0.0f,0.0f };

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		movements = { -speed * fps,0.0f };
		row = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		movements = { speed*fps, 0.0f };
		row = 2;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		movements = { 0.0f,speed*fps };
		row = 3;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		movements = { 0.0f,-speed * fps };
		row = 4;
	}
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) || !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) || !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) 
	{
		row = 0;
	}
		animation.Update(row, fps);
		mySprite.setTextureRect(animation.uvReckt);
		myTransform.setPosition(myTransform.getPosition() + movements);
	
}

void MyEntity::updateInput(float fps,bool is2D) {

	sf::Vector2f movements = { 0.0f,0.0f };

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		movements = { -speed * fps,0.0f };
		animation.Update(1, fps);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		movements = { speed*fps, 0.0f };
		animation.Update(0, fps);
	}
	mySprite.setTextureRect(animation.uvReckt);
	myTransform.setPosition(myTransform.getPosition() + movements);
}
