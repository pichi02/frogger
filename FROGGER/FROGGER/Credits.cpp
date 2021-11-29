#include"Credits.h"
#include"GameManager.h"
#include"Menu.h"

namespace GameManager
{
	namespace Credits
	{
		static char returnToMenu[] = "MENU";
		

		static sf::Vector2i mousePoint;
		static sf::FloatRect mouseRect;
		static sf::RectangleShape menuButtonRect;
		
		sf::Font font;
		sf::Text menuText;
		void GameManager::Credits::InitCredits()
		{
			menuButtonRect.setFillColor(sf::Color::Red);
			menuButtonRect.setSize({ (float)(screenWidth / 4), (float)(screenHeight / 20) });
			menuButtonRect.setPosition(screenWidth * 0.7, screenHeight * 0.8);

			font.loadFromFile("Fonts/AlexandriaFLF.ttf");
			menuText.setFont(font);
			menuText.setString(returnToMenu);
			menuText.setPosition(menuButtonRect.getPosition());
			menuText.setCharacterSize(30);
			menuText.setFillColor(sf::Color::White);
		}

		void GameManager::Credits::UpdateCredits(sf::RenderWindow& rWindow)
		{
			mousePoint = sf::Mouse::getPosition(rWindow);
			mousePoint = (sf::Vector2i)rWindow.mapPixelToCoords(mousePoint);
			sf::FloatRect mouseRect(sf::Vector2f(mousePoint), { 32, 32 });

			if (menuButtonRect.getGlobalBounds().intersects(mouseRect))
			{
				menuButtonRect.setFillColor(sf::Color::Blue);

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					GameManager::Menu::InitMenu();
					currentScreen = MENU;
			
				}
			}
			else menuButtonRect.setFillColor(sf::Color::Red);
		}

		void GameManager::Credits::DrawCredits(sf::RenderWindow& window)
		{
			window.draw(menuButtonRect);
			window.draw(menuText);
	
		}

	}
}
