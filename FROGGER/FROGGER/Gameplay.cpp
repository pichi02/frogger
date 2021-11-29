#include "Gameplay.h"
#include"Car.h"
#include"Frog.h"
#include"GameManager.h"

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
		sf::RectangleShape frogRect({ 30.0f,22.0f });
		sf::RectangleShape carRect({ 40.0f ,17.0f });
		sf::RectangleShape woodRect({ 120.0f ,24.0f });
		sf::RectangleShape waterRect({ (float)screenWidth ,(float)screenHeight / 2.13f });
		sf::RectangleShape goalRect({ 30.0f,30.0f });
		sf::RectangleShape busRect({ 70.0f,18.0f });

		Frog::Frog* frog = new Frog::Frog(frogRect, { screenWidth / 2 - frogRect.getSize().x / 2,screenHeight * 0.96f }, 40.3f);
		Rect::Rect* car[carsCount];
		Rect::Rect* woodsRow1[woodsPerRow];
		Rect::Rect* woodsRow2[woodsPerRow];
		Rect::Rect* woodsRow3[woodsPerRow];
		Rect::Rect* woodsRow4[woodsPerRow];
		Rect::Rect* woodsRow5[woodsPerRow];
		Rect::Rect* waterHitBox;
		Rect::Rect* goals[goalsCount];

		bool isGoalCollected[goalsCount] = { false };

		sf::Font font;
		sf::Text lifeText;

		sf::Sprite gameplaySprite;
		sf::Texture gameplayTexture;

		void GameManager::Gameplay::InitValues()
		{
			gameplayTexture.loadFromFile("Textures/froggerBackground.png");

			gameplaySprite.setTexture(gameplayTexture);

			gameOver = false;
			speedVariation = 0.05f;
			woodRect.setFillColor(sf::Color::Green);
			frogRect.setFillColor(sf::Color::Transparent);
			carRect.setFillColor(sf::Color::Blue);
			waterRect.setFillColor(sf::Color::Blue);
			goalRect.setFillColor(sf::Color::Magenta);

			frog->SetPosition({ screenWidth / 2 - frogRect.getSize().x / 2,screenHeight * 0.96f });

			waterHitBox = new Rect::Rect(waterRect, { 0,0 }, 0.0f);
			for (int i = 0; i < woodsPerRow; i++)
			{
				woodsRow1[i] = new Rect::Rect(woodRect, { screenWidth / 3.0f * i + woodRect.getSize().x * 3.0f , screenHeight / 2.45f }, 0.04f, "Textures/logs.png");
				woodsRow2[i] = new Rect::Rect(woodRect, { screenWidth / 3.0f * i + woodRect.getSize().x * 3.0f , screenHeight / 2.90f }, -0.07f, "Textures/logs.png");
				woodsRow3[i] = new Rect::Rect(woodRect, { screenWidth / 3.0f * i + woodRect.getSize().x * 3.0f , screenHeight / 3.5f }, 0.06f, "Textures/logs.png");
				woodsRow4[i] = new Rect::Rect(woodRect, { screenWidth / 3.0f * i + woodRect.getSize().x * 3.0f , screenHeight / 4.6f }, -0.06f, "Textures/logs.png");
				woodsRow5[i] = new Rect::Rect(woodRect, { screenWidth / 3.0f * i + woodRect.getSize().x * 3.0f , screenHeight / 6.2f }, 0.06f, "Textures/logs.png");

			}
			for (int i = 0; i < goalsCount; i++)
			{
				goals[i] = new Rect::Rect(goalRect, { 0.0f,0.0f }, 0.0f);
				goals[i]->SetPos({ screenWidth / (float)goalsCount * i + (screenWidth * 5 / 100) + i * 12 , screenHeight * 6.5f / 100.0f });
			}

			for (int i = 0; i < carsCount; i++)
			{
				if (i % 2 == 0)
				{
					if (i == 0)
					{
						car[i] = new Rect::Rect(busRect, { screenWidth / 2.0f, screenHeight / 1.6f + i * screenHeight * 0.067f }, 0.07, "Textures/truck.png");
					}
					else
					{
						car[i] = new Rect::Rect(carRect, { screenWidth / 2.0f, screenHeight / 1.6f + i * screenHeight * 0.067f }, 0.15 + i * speedVariation, "Textures/greenCar.png");
					}

				}
				else
				{
					car[i] = new Rect::Rect(carRect, { screenWidth / 2.0f, screenHeight / 1.6f + i * screenHeight * 0.067f }, -0.15 - i * speedVariation, "Textures/blueCar.png");
				}

			}

			font.loadFromFile("Fonts/JungleAdventurer.ttf");
			lifeText.setFont(font);
			lifeText.setPosition(700, 560);
			lifeText.setCharacterSize(30);
			lifeText.setFillColor(sf::Color::Yellow);
			lifeText.setStyle(sf::Text::Bold);
		}

		void GameManager::Gameplay::UpdateRects(sf::RenderWindow& window, sf::Event& event)
		{
			lifeText.setString("Lifes: " + std::to_string(frog->GetLifes()));

			for (int i = 0; i < carsCount; i++)
			{
				car[i]->Move(screenWidth);
				if (frog->Collision(car[i]->GetRectShape()))
				{
					InitValues();
					frog->SubstractLife();
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
						frog->IncreaseGoalsCollected();
						if (frog->GetCollectedGoals() < 5)
						{
							isGoalCollected[i] = true;

							InitValues();
						}
						else
						{
							win = true;
						}
					}
				}
			}

			frog->SetSpritePosition(frog->GetPosition());
			
			for (int i = 0; i < woodsPerRow; i++)
			{
				woodsRow1[i]->SetSpritePosition(woodsRow1[i]->GetPos());
				woodsRow2[i]->SetSpritePosition(woodsRow2[i]->GetPos());
				woodsRow3[i]->SetSpritePosition(woodsRow3[i]->GetPos());
				woodsRow4[i]->SetSpritePosition(woodsRow4[i]->GetPos());
				woodsRow5[i]->SetSpritePosition(woodsRow5[i]->GetPos());
			}

			for (int i = 0; i < carsCount; i++)
			{
				car[i]->SetSpritePosition(car[i]->GetPos());
			}

			if (!CheckLogsCollision() && frog->Collision(waterRect) && !CheckGoalsCollision())
			{
				InitValues();
				frog->SubstractLife();
			}
			if (frog->GetLifes() == 0)
			{
				gameOver = true;
			}
			if (win)
			{
				currentScreen = GAMEOVER;
			}
			else if (gameOver)
			{
				currentScreen = GAMEOVER;
			}

		}

		void GameManager::Gameplay::Draw(sf::RenderWindow& window)
		{
			window.draw(waterHitBox->GetRectShape());
			window.draw(gameplaySprite);
			for (int i = 0; i < carsCount; i++)
			{
				window.draw(car[i]->GetRectSprite());
			}
			for (int i = 0; i < woodsPerRow; i++)
			{
				window.draw(woodsRow1[i]->GetRectSprite());
				window.draw(woodsRow2[i]->GetRectSprite());
				window.draw(woodsRow3[i]->GetRectSprite());
				window.draw(woodsRow4[i]->GetRectSprite());
				window.draw(woodsRow5[i]->GetRectSprite());
			}

			frog->SetShapePosition();

			window.draw(lifeText);
			window.draw(frog->GetFrogSprite());
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

		bool GameManager::Gameplay::CheckGoalsCollision()
		{
			bool collide = false;
			for (int i = 0; i < goalsCount; i++)
			{
				if (frog->Collision(goals[i]->GetRectShape()))
				{
					collide = true;

				}
			}
			return collide;
		}

		void GameManager::Gameplay::ResetValues()
		{
			InitValues();
			for (int i = 0; i < goalsCount; i++)
			{
				isGoalCollected[i] = false;
			}
			frog = new Frog::Frog(frogRect, { screenWidth / 2 - frogRect.getSize().x / 2,screenHeight * 0.96f }, 40.3f);
		}

		void GameManager::Gameplay::UnloadGameplay()
		{

		}
	}
}