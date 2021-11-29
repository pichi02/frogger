#include "Menu.h"
#include "GameManager.h"
#include"Gameplay.h"

namespace GameManager
{
	namespace Menu
	{
		extern int screenWidth = 800;
		extern int screenHeight = 600;
		static char text1[] = "JUGAR";
		static char text2[] = "SONIDO";
		static char text3[] = "CREDITOS";
		static char text4[] = "SALIR";
		static char text5[] = "V 1.0";
		static int sizeText2 = 0;
		static int sizeText3 = 0;
		static int text1PositionX = 0;
		static int text1PositionY = 0;
		static int text2PositionX = 0;
		static int text2PositionY = 0;
		static int text3PositionX = 0;
		static int text3PositionY = 0;
		static int text4PositionX = 0;
		static int text4PositionY = 0;
		static int text5PositionX = 0;
		static int text5PositionY = 0;
		static sf::Vector2i mousePoint;
		static sf::FloatRect mouseRect;
		static sf::RectangleShape rect1;
		static sf::RectangleShape rect2;
		static sf::RectangleShape rect3;
		static sf::RectangleShape rect4;
		sf::Font font;
		sf::Text startText;
		sf::Text optionsText;
		sf::Text creditsText;
		sf::Text quitText;
		static int halfScreenWidth = 0;
		static int halfScreenHeight = 0;

		//static sf::Image menuImage;
		//static sf::Texture menuImageTexture;
		static float scaleBackground;

		void InitMenu()
		{
			//menuImage.loadFromFile("../res/backgroundMenu.png");
			//menuImageTexture = LoadTextureFromImage(menuImage);
			halfScreenWidth = screenWidth / 2;
			halfScreenHeight = screenHeight / 2;

			/*sizeText2 = (screenWidth * 20) / scaleAux1;
			sizeText3 = (screenWidth * 15) / scaleAux1;
			text1PositionX = halfScreenWidth - MeasureText(text1, sizeText2) / 2;
			text1PositionY = halfScreenHeight + GetScreenHeight() * 0.0333333;
			text2PositionX = halfScreenWidth - MeasureText(text2, sizeText2) / 2;
			text2PositionY = halfScreenHeight + GetScreenHeight() * 0.1333333;
			text3PositionX = halfScreenWidth - MeasureText(text3, sizeText2) / 2;
			text3PositionY = halfScreenHeight + GetScreenHeight() * 0.2333333;
			text4PositionX = halfScreenWidth - MeasureText(text4, sizeText2) / 2;
			text4PositionY = halfScreenHeight + GetScreenHeight() * 0.3333333;
			text5PositionX = GetScreenWidth() * 0.05;
			text5PositionY = GetScreenHeight() * 0.95;*/

			rect1.setFillColor(sf::Color::Red);
			rect2.setFillColor(sf::Color::Red);
			rect3.setFillColor(sf::Color::Red);
			rect4.setFillColor(sf::Color::Red);

			rect1.setSize({ (float)(screenWidth / 4), (float)(screenHeight / 20)});
			rect1.setPosition(halfScreenWidth - rect1.getSize().x / 2, halfScreenHeight + screenHeight * 0.11);

			rect2.setSize({ (float)(screenWidth / 4), (float)(screenHeight / 20)});
			rect2.setPosition(halfScreenWidth - rect2.getSize().x / 2, halfScreenHeight + screenHeight * 0.21);

			rect3.setSize({ (float)(screenWidth / 4), (float)(screenHeight / 20)});
			rect3.setPosition(halfScreenWidth - rect3.getSize().x / 2, halfScreenHeight + screenHeight * 0.31);

			rect4.setSize({ (float)(screenWidth / 4), (float)(screenHeight / 20)});
			rect4.setPosition(halfScreenWidth - rect4.getSize().x / 2, halfScreenHeight + screenHeight * 0.01);

			//scaleBackground = (GetScreenWidth() * 1.0f) / scaleAux3;
			font.loadFromFile("Fonts/AlexandriaFLF.ttf");
			startText.setFont(font);
			startText.setString("START");
			startText.setPosition(rect4.getPosition());
			startText.setCharacterSize(30);
			startText.setFillColor(sf::Color::White);

			optionsText.setFont(font);
			optionsText.setString("OPTIONS");
			optionsText.setPosition(rect1.getPosition());
			optionsText.setCharacterSize(30);
			optionsText.setFillColor(sf::Color::White);

			creditsText.setFont(font);
			creditsText.setString("CREDITS");
			creditsText.setPosition(rect2.getPosition());
			creditsText.setCharacterSize(30);
			creditsText.setFillColor(sf::Color::White);

			quitText.setFont(font);
			quitText.setString("QUIT");
			quitText.setPosition(rect3.getPosition());
			quitText.setCharacterSize(30);
			quitText.setFillColor(sf::Color::White);



		}

		void UpdateMenu(sf::RenderWindow& rWindow)
		{
			mousePoint = sf::Mouse::getPosition(rWindow);
			mousePoint = (sf::Vector2i)rWindow.mapPixelToCoords(mousePoint);
			sf::FloatRect mouseRect(sf::Vector2f(mousePoint), { 32, 32 });

			if (rect1.getGlobalBounds().intersects(mouseRect))
			{
				rect1.setFillColor(sf::Color::Blue);

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					//mute = !mute;
				}
			}
			else rect1.setFillColor(sf::Color::Red);

			if (rect2.getGlobalBounds().intersects(mouseRect))
			{
				rect2.setFillColor(sf::Color::Blue);

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					UnloadMenu();
					GameManager::currentScreen = GameManager::CREDITS;
				}
			}
			else rect2.setFillColor(sf::Color::Red);

			if (rect3.getGlobalBounds().intersects(mouseRect))
			{
				rect3.setFillColor(sf::Color::Blue);

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					isOpen = false;
				}
			}
			else rect3.setFillColor(sf::Color::Red);

			if (rect4.getGlobalBounds().intersects(mouseRect))
			{
				rect4.setFillColor(sf::Color::Blue);

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					UnloadMenu();
					GameManager::Gameplay::InitValues();
					GameManager::currentScreen = GameManager::GAMEPLAY;
				}
			}
			else rect4.setFillColor(sf::Color::Red);
		}

		void DrawMenu(sf::RenderWindow& window)
		{
			window.draw(rect1);
			window.draw(rect2);
			window.draw(rect3);
			window.draw(rect4);
			window.draw(startText);
			window.draw(optionsText);
			window.draw(creditsText);
			window.draw(quitText);

		}

		void UnloadMenu()
		{
			//UnloadTexture(menuImageTexture);
			//UnloadImage(menuImage);
		}
	}
}