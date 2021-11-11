#include <SFML/Graphics.hpp>
#include"GameManager.h"
#include"Gameplay.h"
#include"Frog.h"
#include"Car.h"


namespace GameManager
{
	
	void GameManager()
	{
		int screenWidth = 800;
		int screenHeight = 600;
		sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "FROGGER");
		sf::CircleShape circle(20);
		sf::RectangleShape rect({ 40.0f ,25.0f });
		circle.setFillColor(sf::Color::Green);
		rect.setFillColor(sf::Color::Blue);
		Frog::Frog* frog = new Frog::Frog(circle, { screenWidth / 2 - (circle.getRadius()), screenHeight * 0.9f },0.1f);
		Car::Car* car = new Car::Car(rect, { screenWidth / 2.0f, screenHeight/2.0f }, 0.15);
		
	

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
			car->Move(screenWidth);
			window.draw(frog->GetFrogShape());
			window.draw(car->GetCarShape());
			window.display();
		}
	}
}