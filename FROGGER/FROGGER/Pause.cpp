#include "Pause.h"
#include "GameManager.h"
#include "Gameplay.h"

namespace GameManager
{
	namespace Pause
	{
		extern bool pause = false;

		static sf::Vector2i mousePoint;
		static sf::FloatRect mouseRect;

		static sf::RectangleShape rect1;
		static sf::RectangleShape rect2;

		sf::Font font;
		sf::Text resumeText;
		sf::Text menuText;

		static int halfScreenWidth = 0;
		static int halfScreenHeight = 0;

		static sf::Sprite pauseSprite;
		static sf::Texture pauseTexture;

		void InitPause()
		{
			pauseTexture.loadFromFile("Textures/pauseBackground.png");

			pauseSprite.setTexture(pauseTexture);

			halfScreenWidth = screenWidth / 2;
			halfScreenHeight = screenHeight / 2;

			rect1.setFillColor(sf::Color::Cyan);
			rect2.setFillColor(sf::Color::Cyan);

			rect1.setSize({ (float)(screenWidth / 4), (float)(screenHeight / 20) });
			rect1.setPosition(screenWidth * 0.1, screenHeight * 0.8);

			rect2.setSize({ (float)(screenWidth / 4), (float)(screenHeight / 20) });
			rect2.setPosition(screenWidth * 0.7, screenHeight * 0.8);

			font.loadFromFile("Fonts/JungleAdventurer.ttf");
			resumeText.setFont(font);
			resumeText.setString("MENU");
			resumeText.setPosition({ screenWidth * 0.84f - menuText.getCharacterSize() - 20.0f, screenHeight * 0.795f });
			resumeText.setCharacterSize(30);
			resumeText.setFillColor(sf::Color::White);

			menuText.setFont(font);
			menuText.setString("RESUME");
			menuText.setPosition({ screenWidth * 0.18f, screenHeight * 0.795f });
			menuText.setCharacterSize(30);
			menuText.setFillColor(sf::Color::White);
		}

		void UpdatePause(sf::RenderWindow& rWindow)
		{
			mousePoint = sf::Mouse::getPosition(rWindow);
			mousePoint = (sf::Vector2i)rWindow.mapPixelToCoords(mousePoint);
			sf::FloatRect mouseRect(sf::Vector2f(mousePoint), { 32, 32 });

			if (rect1.getGlobalBounds().intersects(mouseRect))
			{
				rect1.setFillColor(sf::Color::Cyan);

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					GameManager::Gameplay::pause = false;
					GameManager::currentScreen = GameManager::GAMEPLAY;
				}
			}
			else rect1.setFillColor(sf::Color::Blue);

			if (rect2.getGlobalBounds().intersects(mouseRect))
			{
				rect2.setFillColor(sf::Color::Cyan);

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					GameManager::Gameplay::pause = false;
					GameManager::currentScreen = GameManager::MENU;
				}
			}
			else rect2.setFillColor(sf::Color::Blue);
		}

		void DrawPause(sf::RenderWindow& window)
		{
			window.draw(pauseSprite);
			window.draw(rect1);
			window.draw(rect2);
			window.draw(resumeText);
			window.draw(menuText);
		}

		void UnloadPause()
		{

		}
	}
}