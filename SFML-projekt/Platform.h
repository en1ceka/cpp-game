#pragma once
#include <SFML\Graphics.hpp>
#include "Collider.h"
class Platform
{
public:
	Platform(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position);

	void draw(sf::RenderWindow& window);

	Collider getCollider() { return Collider(body); }
	void setTexture(int x, int y);
private:
	sf::RectangleShape body;
};

