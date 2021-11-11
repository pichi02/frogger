#include <SFML/Graphics.hpp>
#include"GameManager.h"
#include"Gameplay.h"
#include"Frog.h"


namespace GameManager
{
	
	void GameManager()
	{
		int screenWidth = 800;
		int screenHeight = 600;
		sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "FROGGER");
		sf::CircleShape circle(20);
		circle.setFillColor(sf::Color::Green);
		Frog::Frog* frog = new Frog::Frog(circle, { screenWidth / 2 - (circle.getRadius()), screenHeight * 0.9f });
		
	

		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}
			
			window.clear();
			frog->Move(window);
			window.draw(frog->GetFrogShape());
			window.display();
		}
	}
}