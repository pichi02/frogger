#include "Gameplay.h"
#include"Car.h"
#include"Frog.h"

namespace GameManager
{
	namespace Gameplay
	{
		const int carsCount = 4;
		float speedVariation;
		int screenWidth = 800;
		int screenHeight = 600;
		bool gameOver = false;
		sf::RectangleShape frogRect({ 18.0f,18.0f });
		sf::RectangleShape rect({ 40.0f ,17.0f });
		Frog::Frog* frog;
		Car::Car* car[carsCount];


		void GameManager::Gameplay::InitValues()
		{
			frog = new Frog::Frog(frogRect, { screenWidth / 2 - frogRect.getSize().x / 2,screenHeight * 0.87f }, 30.3f);
			speedVariation = 0.05f;
			frogRect.setFillColor(sf::Color::Green);
			rect.setFillColor(sf::Color::Blue);

			for (int i = 0; i < carsCount; i++)
			{
				if (i % 2 == 0)
				{
					car[i] = new Car::Car(rect, { screenWidth / 2.0f, screenHeight / 1.5f + i * screenHeight * 0.05f }, 0.15 + i * speedVariation);
				}
				else
				{
					car[i] = new Car::Car(rect, { screenWidth / 2.0f, screenHeight / 1.5f + i * screenHeight * 0.05f }, -0.15 - i * speedVariation);
				}

			}
		}

		void GameManager::Gameplay::UpdateCar(sf::RenderWindow& window, sf::Event& event)
		{

			for (int i = 0; i < carsCount; i++)
			{
				car[i]->Move(screenWidth);
				if (frog->Collision(car[i]->GetCarShape()))
				{
					gameOver = true;
				}

			}

		}
		

		void GameManager::Gameplay::Draw(sf::RenderWindow& window)
		{

			for (int i = 0; i < carsCount; i++)
			{
				window.draw(car[i]->GetCarShape());
			
			}
			frog->Draw();
			window.draw(frog->GetFrogShape());
		}

		void UpdateFrog(sf::RenderWindow& window, sf::Event& event)
		{
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

		void GameManager::Gameplay::ResetValues()
		{
		}

		void GameManager::Gameplay::UnloadGameplay()
		{
		}
	}
}