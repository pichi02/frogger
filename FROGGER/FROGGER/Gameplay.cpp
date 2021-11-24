#include "Gameplay.h"
#include"Car.h"
#include"Frog.h"

namespace GameManager
{
	namespace Gameplay
	{
		const int carsCount = 4;
		const int woodsPerRow = 3;

		float speedVariation;
		int screenWidth = 800;
		int screenHeight = 600;
		extern bool gameOver = false;
		bool isInWood = false;
		sf::RectangleShape frogRect({ 18.0f,18.0f });
		sf::RectangleShape carRect({ 40.0f ,17.0f });
		sf::RectangleShape woodRect({ 120.0f ,17.0f });

		Frog::Frog* frog;
		Rect::Rect* car[carsCount];
		Rect::Rect* woodsRow1[woodsPerRow];
		Rect::Rect* woodsRow2[woodsPerRow];
		Rect::Rect* woodsRow3[woodsPerRow];


		void GameManager::Gameplay::InitValues()
		{
			frog = new Frog::Frog(frogRect, { screenWidth / 2 - frogRect.getSize().x / 2,screenHeight * 0.87f }, 30.3f);


			speedVariation = 0.05f;
			woodRect.setFillColor(sf::Color::Green);
			frogRect.setFillColor(sf::Color::Green);
			carRect.setFillColor(sf::Color::Blue);

			for (int i = 0; i < woodsPerRow; i++)
			{
				woodsRow1[i] = new Rect::Rect(woodRect, { screenWidth / 2.0f + i * woodRect.getSize().x * 2.5f , screenHeight / 2.15f }, 0.04f);
				woodsRow2[i] = new Rect::Rect(woodRect, { screenWidth / 2.0f + i * woodRect.getSize().x * 2.5f , screenHeight / 2.40f }, 0.06f);
			}
			for (int i = 0; i < carsCount; i++)
			{
				if (i % 2 == 0)
				{
					car[i] = new Rect::Rect(carRect, { screenWidth / 2.0f, screenHeight / 1.5f + i * screenHeight * 0.05f }, 0.15 + i * speedVariation);
				}
				else
				{
					car[i] = new Rect::Rect(carRect, { screenWidth / 2.0f, screenHeight / 1.5f + i * screenHeight * 0.05f }, -0.15 - i * speedVariation);
				}

			}
		}

		void GameManager::Gameplay::UpdateRects(sf::RenderWindow& window, sf::Event& event)
		{

			for (int i = 0; i < carsCount; i++)
			{
				car[i]->Move(screenWidth);
				if (frog->Collision(car[i]->GetCarShape()))
				{
					gameOver = true;
				}

			}
			for (int i = 0; i < woodsPerRow; i++)
			{
				woodsRow1[i]->Move(screenWidth);
				woodsRow2[i]->Move(screenWidth);


				if (!isInWood&&(frog->Collision(woodsRow1[i]->GetCarShape()) || frog->Collision(woodsRow2[i]->GetCarShape())))
				{
					isInWood = true;
					frog->SetPosition({ frog->GetPosition().x - woodsRow1[i]->GetSpeed(), frog->GetPosition().y });

				}

			}
			for (int i = 0; i < woodsPerRow; i++)
			{

				if ((!frog->Collision(woodsRow1[i]->GetCarShape()) && !frog->Collision(woodsRow2[i]->GetCarShape())) && frog->GetPosition().y < woodsRow1[i]->GetPos().y+woodRect.getSize().y)
				{
					frog->SubstractLife();
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
			for (int i = 0; i < woodsPerRow; i++)
			{
				window.draw(woodsRow1[i]->GetCarShape());
				window.draw(woodsRow2[i]->GetCarShape());

			}


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