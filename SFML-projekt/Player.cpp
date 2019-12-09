#include "Player.h"

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) :
	animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	row = 0;
	faceRight = true;


	body.setSize(sf::Vector2f(100.0f, 100.0f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(206.0f, 206.0f);
	body.setTexture(texture);
}

void Player::update(float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);

	row = 0;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) 
	{
		row = 2;
		movement.x -= speed * deltaTime;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		row = 3;
		movement.x += speed * deltaTime;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		row = 4;
		movement.y -= speed * deltaTime;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		row = 1;
		movement.y += speed * deltaTime;
	}

	
	
	animation.update(row, deltaTime, faceRight);
	body.setTextureRect(animation.uvRect);
	body.move(movement);
}


void Player::draw(sf::RenderWindow& window)
{
	window.draw(body);
}