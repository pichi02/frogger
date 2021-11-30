#include"GameOver.h"
#include"GameManager.h"
#include"Gameplay.h"
#include"Menu.h"
namespace GameManager
{
	namespace GameOver
	{
		
		
		static sf::Vector2i mousePoint;
		static sf::FloatRect mouseRect;
		static sf::RectangleShape menuButtonRect;
		static sf::RectangleShape playButtonRect;
	
		sf::Font font;
		sf::Text playText;
		sf::Text menuText;
		sf::Text victoryText;
		sf::Text loseText;

		sf::Texture backgroundTexture;
		sf::Sprite backgroundSprite;
		void InitGameOver()
		{
			
			menuButtonRect.setFillColor(sf::Color::Blue);
			playButtonRect.setFillColor(sf::Color::Blue);
			

			menuButtonRect.setSize({ (float)(screenWidth / 4), (float)(screenHeight / 20) });
			menuButtonRect.setPosition(screenWidth*0.7, screenHeight * 0.8);

			playButtonRect.setSize({ (float)(screenWidth / 4), (float)(screenHeight / 20) });
			playButtonRect.setPosition(screenWidth * 0.1, screenHeight * 0.8);

			

			font.loadFromFile("Fonts/JungleAdventurer.ttf");
			playText.setFont(font);
			playText.setString("PLAY");
			playText.setPosition({ screenWidth * 0.18f, screenHeight * 0.795f });
			playText.setCharacterSize(30);
			playText.setFillColor(sf::Color::White);

			menuText.setFont(font);
			menuText.setString("MENU");
			menuText.setPosition({ screenWidth * 0.84f - menuText.getCharacterSize() - 20.0f, screenHeight * 0.795f });
			menuText.setCharacterSize(30);
			menuText.setFillColor(sf::Color::White);

			victoryText.setFont(font);
			victoryText.setString("YOU WIN!");
			victoryText.setPosition({ screenWidth * 0.4f, screenHeight * 0.3f });
			victoryText.setCharacterSize(50);
			victoryText.setFillColor(sf::Color::White);

			loseText.setFont(font);
			loseText.setString("YOU LOSE D:");
			loseText.setPosition({ screenWidth * 0.37f, screenHeight * 0.3f });
			loseText.setCharacterSize(50);
			loseText.setFillColor(sf::Color::White);

			backgroundTexture.loadFromFile("Textures/gameOverBackground.png");
			backgroundSprite.setTexture(backgroundTexture);
		}

		void UpdateGameOver(sf::RenderWindow& rWindow)
		{
			mousePoint = sf::Mouse::getPosition(rWindow);
			mousePoint = (sf::Vector2i)rWindow.mapPixelToCoords(mousePoint);
			sf::FloatRect mouseRect(sf::Vector2f(mousePoint), { 32, 32 });

			if (playButtonRect.getGlobalBounds().intersects(mouseRect))
			{
				playButtonRect.setFillColor(sf::Color::Cyan);

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					GameManager::Gameplay::ResetValues();
					GameManager::Gameplay::InitValues();
					currentScreen = GAMEPLAY;
				}
				
			}
			else playButtonRect.setFillColor(sf::Color::Blue);

			if (menuButtonRect.getGlobalBounds().intersects(mouseRect))
			{
				menuButtonRect.setFillColor(sf::Color::Cyan);

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					currentScreen = MENU;
					GameManager::Menu::InitMenu();
					UnloadGameOver();
				}
			}
			else menuButtonRect.setFillColor(sf::Color::Blue);
		}

		void DrawGameOver(sf::RenderWindow& window)
		{
			window.draw(backgroundSprite);
			window.draw(playButtonRect);
			window.draw(menuButtonRect);
			window.draw(menuText);
			window.draw(playText);
			
			if (GameManager::Gameplay::win)
			{
				window.draw(victoryText);
			}
			else if (GameManager::Gameplay::gameOver)
			{
				window.draw(loseText);
			}
		}

		void GameOver::UnloadGameOver()
		{

		}
	}
}