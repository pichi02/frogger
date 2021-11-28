#include "Gameplay.h"
#include"Car.h"
#include"Frog.h"

namespace GameManager
{
	namespace Gameplay
	{
		const int carsCount = 5;
		const int woodsPerRow = 3;
		const int goalsCount = 5;

		float speedVariation;
		int screenWidth = 800;
		int screenHeight = 600;
		extern bool gameOver = false;
		extern bool win = false;
		bool isInWood = false;
		sf::RectangleShape frogRect({ 18.0f,18.0f });
		sf::RectangleShape carRect({ 40.0f ,17.0f });
		sf::RectangleShape woodRect({ 120.0f ,24.0f });
		sf::RectangleShape waterRect({ (float)screenWidth ,(float)screenHeight / 2.13f });
		sf::RectangleShape goalRect({ 30.0f,30.0f });
		sf::RectangleShape busRect({ 70.0f,18.0f });

		Frog::Frog* frog;
		Rect::Rect* car[carsCount];
		Rect::Rect* woodsRow1[woodsPerRow];
		Rect::Rect* woodsRow2[woodsPerRow];
		Rect::Rect* woodsRow3[woodsPerRow];
		Rect::Rect* woodsRow4[woodsPerRow];
		Rect::Rect* woodsRow5[woodsPerRow];
		Rect::Rect* waterHitBox;
		Rect::Rect* goals[goalsCount];

		bool isGoalCollected[goalsCount] = { false };


		void GameManager::Gameplay::InitValues()
		{
			frog = new Frog::Frog(frogRect, { screenWidth / 2 - frogRect.getSize().x / 2,screenHeight * 0.96f }, 40.3f);


			speedVariation = 0.05f;
			woodRect.setFillColor(sf::Color::Green);
			frogRect.setFillColor(sf::Color::White);
			carRect.setFillColor(sf::Color::Blue);
			waterRect.setFillColor(sf::Color::Blue);
			goalRect.setFillColor(sf::Color::Magenta);

			waterHitBox = new Rect::Rect(waterRect, { 0,0 }, 0.0f);
			for (int i = 0; i < woodsPerRow; i++)
			{
				woodsRow1[i] = new Rect::Rect(woodRect, { screenWidth / 3.0f * i + woodRect.getSize().x * 3.0f , screenHeight / 2.45f }, 0.04f);
				woodsRow2[i] = new Rect::Rect(woodRect, { screenWidth / 3.0f * i + woodRect.getSize().x * 3.0f , screenHeight / 2.90f }, -0.07f);
				woodsRow3[i] = new Rect::Rect(woodRect, { screenWidth / 3.0f * i + woodRect.getSize().x * 3.0f , screenHeight / 3.5f }, 0.06f);
				woodsRow4[i] = new Rect::Rect(woodRect, { screenWidth / 3.0f * i + woodRect.getSize().x * 3.0f , screenHeight / 4.6f }, -0.06f);
				woodsRow5[i] = new Rect::Rect(woodRect, { screenWidth / 3.0f * i + woodRect.getSize().x * 3.0f , screenHeight / 6.2f }, 0.06f);

			}
			for (int i = 0; i < goalsCount; i++)
			{
				goals[i] = new Rect::Rect(goalRect, { 0.0f,0.0f }, 0.0f);
				goals[i]->SetPos({ screenWidth / (float)goalsCount * i + (screenWidth * 5 / 100) , screenHeight * 6.5f / 100.0f });
			}
			for (int i = 0; i < carsCount; i++)
			{
				if (i % 2 == 0)
				{
					if (i == 0)
					{
						car[i] = new Rect::Rect(busRect, { screenWidth / 2.0f, screenHeight / 1.6f + i * screenHeight * 0.067f }, 0.07);
					}
					else
					{
						car[i] = new Rect::Rect(carRect, { screenWidth / 2.0f, screenHeight / 1.6f + i * screenHeight * 0.067f }, 0.15 + i * speedVariation);
					}

				}
				else
				{
					car[i] = new Rect::Rect(carRect, { screenWidth / 2.0f, screenHeight / 1.6f + i * screenHeight * 0.067f }, -0.15 - i * speedVariation);
				}

			}
		}

		void GameManager::Gameplay::UpdateRects(sf::RenderWindow& window, sf::Event& event)
		{

			for (int i = 0; i < carsCount; i++)
			{
				car[i]->Move(screenWidth);
				if (frog->Collision(car[i]->GetRectShape()))
				{
					gameOver = true;
				}

			}
			isInWood = false;
			for (int i = 0; i < woodsPerRow; i++)
			{
				woodsRow1[i]->Move(screenWidth);
				woodsRow2[i]->Move(screenWidth);
				woodsRow3[i]->Move(screenWidth);
				woodsRow4[i]->Move(screenWidth);
				woodsRow5[i]->Move(screenWidth);

				if (GameManager::Gameplay::CheckLogsCollision())
				{


					if (frog->Collision(woodsRow2[i]->GetRectShape()))
					{
						frog->SetPosition({ frog->GetPosition().x - woodsRow2[0]->GetSpeed(),frog->GetPosition().y });
					}
					else if (frog->Collision(woodsRow1[i]->GetRectShape()))
					{
						frog->SetPosition({ frog->GetPosition().x - woodsRow1[0]->GetSpeed(),frog->GetPosition().y });
					}
					else if (frog->Collision(woodsRow3[i]->GetRectShape()))
					{
						frog->SetPosition({ frog->GetPosition().x - woodsRow3[0]->GetSpeed(),frog->GetPosition().y });
					}
					else if (frog->Collision(woodsRow4[i]->GetRectShape()))
					{
						frog->SetPosition({ frog->GetPosition().x - woodsRow4[0]->GetSpeed(),frog->GetPosition().y });
					}
					else if (frog->Collision(woodsRow5[i]->GetRectShape()))
					{
						frog->SetPosition({ frog->GetPosition().x - woodsRow5[0]->GetSpeed(),frog->GetPosition().y });
					}

				}
			}
			for (int i = 0; i < goalsCount; i++)
			{

				if (frog->Collision(goals[i]->GetRectShape()))
				{
					if (!isGoalCollected[i])
					{
						if (frog->GetCollectedGoals() < 5)
						{
							isGoalCollected[i] = true;
							ResetValues();
						}
						else
						{
							win = true;
						}
					}


				}
			}



			/*	bool frogWaterCollide = frog->Collision(waterRect);
				if (!CheckLogsCollision() && frogWaterCollide)
				{
					gameOver = true;
				}*/

		}


		void GameManager::Gameplay::Draw(sf::RenderWindow& window)
		{

			for (int i = 0; i < carsCount; i++)
			{
				window.draw(car[i]->GetRectShape());

			}

			window.draw(waterHitBox->GetRectShape());


			for (int i = 0; i < woodsPerRow; i++)
			{
				window.draw(woodsRow1[i]->GetRectShape());
				window.draw(woodsRow2[i]->GetRectShape());
				window.draw(woodsRow3[i]->GetRectShape());
				window.draw(woodsRow4[i]->GetRectShape());
				window.draw(woodsRow5[i]->GetRectShape());

			}
			frog->SetShapePosition();
			window.draw(frog->GetFrogShape());
			for (int i = 0; i < goalsCount; i++)
			{
				window.draw(goals[i]->GetRectShape());
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
		bool GameManager::Gameplay::CheckLogsCollision()
		{
			bool collide = false;
			for (int i = 0; i < woodsPerRow; i++)
			{
				if (frog->Collision(woodsRow1[i]->GetRectShape()) || frog->Collision(woodsRow2[i]->GetRectShape()) || frog->Collision(woodsRow3[i]->GetRectShape()) || frog->Collision(woodsRow4[i]->GetRectShape()) || frog->Collision(woodsRow5[i]->GetRectShape()))
				{
					collide = true;

				}

			}
			return collide;
		}

		void GameManager::Gameplay::ResetValues()
		{
			InitValues();
		}

		void GameManager::Gameplay::UnloadGameplay()
		{
		}
	}
}