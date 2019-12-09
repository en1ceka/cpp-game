
#include <iostream>
#include <SFML\Graphics.hpp>
#include "Animation.h"
#include "Player.h"
#include "Platform.h"

static const float VIEW_HEIGHT = 1080.0f;

void ResizeView(const sf::RenderWindow& window, sf::View& view)
{
	float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
	view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(512,512), "SFML works!", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(1920.0f, 1080.0f)); 

	sf::Texture playerTexture;
	playerTexture.loadFromFile("git2.png");

	Player player(&playerTexture, sf::Vector2u(12, 5), 0.01f, 1000.0f);

	Platform* platform[1000];
	Platform platform1(nullptr, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(50.0f, 50.0F));
	Platform platform2(nullptr, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(100.0f, 50.0F));
	

	for (int i = 1; i < 1000; i++) {
		platform[i] = new Platform(nullptr, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(50.0f * float(i%100), 50.0F*(float)(i / 100)));
	}

	float deltaTime = 0.0f;
	sf::Clock clock;

	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();

		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::Resized:
				std::cout << "new width " << event.size.width << "new height " << event.size.height << std::endl;
				break;
			case sf::Event::MouseButtonPressed:
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					std::cout << "the right button was pressed" << std::endl;
					std::cout << "mouse x: " << event.mouseButton.x << std::endl;
					std::cout << "mouse y: " << event.mouseButton.y << std::endl;
					for (int i = 1; i < 1000; i++) {
						platform[i]->setTexture(event.mouseButton.x, event.mouseButton.y);

					}
				}
			}
				
		}

		player.update(deltaTime);

		for (int i = 1; i < 1000; i++) {
			Collider b = player.getCollider();
			platform[i]->getCollider().checkCollision(b, 1.0f);

		}
		view.setCenter(player.getPosition());
		
		window.clear(sf::Color(150,150,150));
		window.setView(view);
	
		player.draw(window);
		for (int i = 1; i < 1000; i++) {
			platform[i]->draw(window);

		}
		window.display();
	}

	return 0; 
}

