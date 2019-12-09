#include "Platform.h"
#include <iostream>

Platform::Platform(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position)
{
	body.setSize(size);
	body.setOrigin(size / 2.0f);
	body.setTexture(texture);
	body.setPosition(position);
}
void Platform::draw(sf::RenderWindow& window)
{
	window.draw(body);
}

void Platform::setTexture(int x, int y)
{
	if (body.getPosition().x < x && (body.getPosition().x + 50) > x
		&& body.getPosition().y < y && (body.getPosition().y + 50) > y) {

		body.setFillColor(sf::Color::Blue);
		std::cout << "x, y: " << body.getPosition().x << ", " << body.getPosition().y << std::endl;
	}
}
