#include "Rules.h"
#include "GameManager.h"
#include "Menu.h"

namespace GameManager
{
	namespace Rules
	{
		static char returnToMenu[] = "MENU";

		static sf::Vector2i mousePoint;
		static sf::FloatRect mouseRect;
		static sf::RectangleShape menuButtonRect;

		sf::Font font;
		sf::Text rulesText;

		sf::Texture rulesTexture;
		sf::Sprite rulesSprite;

		void InitRules()
		{
			menuButtonRect.setFillColor(sf::Color::Blue);
			menuButtonRect.setSize({ (float)(screenWidth / 4), (float)(screenHeight / 20) });
			menuButtonRect.setPosition(screenWidth * 0.7, screenHeight * 0.8);

			font.loadFromFile("Fonts/JungleAdventurer.ttf");
			rulesText.setFont(font);
			rulesText.setString(returnToMenu);
			rulesText.setPosition({ screenWidth * 0.84f - rulesText.getCharacterSize() - 20.0f, screenHeight * 0.795f });
			rulesText.setCharacterSize(30);
			rulesText.setFillColor(sf::Color::White);
			rulesTexture.loadFromFile("Textures/rulesBackground.png");
			rulesSprite.setTexture(rulesTexture);
		}

		void UpdateRules(sf::RenderWindow& rWindow)
		{
			mousePoint = sf::Mouse::getPosition(rWindow);
			mousePoint = (sf::Vector2i)rWindow.mapPixelToCoords(mousePoint);
			sf::FloatRect mouseRect(sf::Vector2f(mousePoint), { 32, 32 });

			if (menuButtonRect.getGlobalBounds().intersects(mouseRect))
			{
				menuButtonRect.setFillColor(sf::Color::Cyan);

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					GameManager::Menu::InitMenu();
					currentScreen = MENU;
			
				}
			}
			else menuButtonRect.setFillColor(sf::Color::Blue);
		}

		void DrawRules(sf::RenderWindow& window)
		{
			window.draw(rulesSprite);
			window.draw(menuButtonRect);
			window.draw(rulesText);
		}

		void UnloadRules()
		{

		}
	}
}