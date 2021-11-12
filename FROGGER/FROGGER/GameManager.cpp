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
		float speedVariation = 0.05f;
		const int carsCount = 4;
		sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "FROGGER");
		sf::CircleShape circle(10);
		sf::RectangleShape rect({ 40.0f ,17.0f });
		circle.setFillColor(sf::Color::Green);
		rect.setFillColor(sf::Color::Blue);
		Frog::Frog* frog = new Frog::Frog(circle, { screenWidth / 2 - (circle.getRadius()), screenHeight * 0.87f }, 30.3f);
		Car::Car* car[carsCount];/* = new Car::Car(rect, { screenWidth / 2.0f, screenHeight/2.0f }, 0.15);*/
		for (int i = 0; i < carsCount; i++)
		{
			if (i%2==0)
			{
				car[i] = new Car::Car(rect, { screenWidth / 2.0f, screenHeight / 1.5f + i * screenHeight * 0.05f }, 0.15+i*speedVariation );
			}
			else
			{
				car[i] = new Car::Car(rect, { screenWidth / 2.0f, screenHeight / 1.5f + i * screenHeight * 0.05f }, -0.15 - i * speedVariation);
			}
			
		}


		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();

				switch (event.type)
				{
				case sf::Event::KeyReleased:
					switch (event.key.code)
					{
					case sf::Keyboard::W:
						frog->MoveUp();
						break;
					case sf::Keyboard::A:
						frog->MoveLeft();
						break;
					case sf::Keyboard::S:
						frog->MoveDown();
						break;
					case sf::Keyboard::D:
						frog->MoveRight();
						break;
					default:
						break;
					}
				default:
					break;
				}

			}
			window.clear();

			for (int i = 0; i < carsCount; i++)
			{
				car[i]->Move(screenWidth);
				window.draw(car[i]->GetCarShape());

			}

			frog->Draw();
			window.draw(frog->GetFrogShape());

			window.display();

		}

	
	}
}
