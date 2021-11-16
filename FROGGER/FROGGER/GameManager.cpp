#include <SFML/Graphics.hpp>
#include"GameManager.h"
//#include"Gameplay.h"
//#include"Frog.h"
//#include"Car.h"
#include"Menu.h"
#include"Gameplay.h"

using namespace Gamemanager::menu;

namespace GameManager
{
	extern bool gameOver;
	void GameManager()
	{
		int screenWidth = 800;
		int screenHeight = 600;


		sf::RenderWindow GameWindow(sf::VideoMode(screenWidth, screenHeight), "FROGGER");
		Menu Menu(GameWindow.getSize().x, GameWindow.getSize().y);
		GameManager::Gameplay::InitValues();
		while (GameWindow.isOpen()/*&&!gameOver*/)
		{
			sf::Event event;
			while (GameWindow.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					GameWindow.close();
				}

				/*if (event.type == sf::Event::KeyReleased)
				{
					if (event.key.code == sf::Keyboard::Up)
					{
						Menu.MoveUp();
						break;
					}

					if (event.key.code == sf::Keyboard::Down)
					{
						Menu.MoveDown();
						break;
					}

					if (event.key.code == sf::Keyboard::Return)
					{
						int x = Menu.MenuPressed();
					}

				}*/
				GameManager::Gameplay::UpdateFrog(GameWindow, event);
			}
			GameWindow.clear();
			GameManager::Gameplay::UpdateCar(GameWindow, event);
			GameManager::Gameplay::Draw(GameWindow);
			GameWindow.display();
		}

		
	}
}
