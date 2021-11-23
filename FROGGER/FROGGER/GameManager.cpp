#include <SFML/Graphics.hpp>

#include "GameManager.h"
#include"Frog.h"
#include"Car.h"
#include "Menu.h"
#include "Gameplay.h"

namespace GameManager
{
	using namespace Gameplay;
	int screenWidth = 800;
	int screenHeight = 600;

	screens currentScreen = MENU;

	void InitGame()
	{
		GameManager::Gameplay::InitValues();
		Gamemanager::menu::InitMenu();
	}

	void GameManager()
	{
		sf::RenderWindow GameWindow(sf::VideoMode(GameManager::screenWidth, GameManager::screenHeight), "FROGGER");

		while (GameWindow.isOpen() && !gameOver)
		{
			sf::Event event;
			while (GameWindow.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					GameWindow.close();
					
				}
			}

			GameWindow.clear();
			switch (currentScreen)
			{
			case GameManager::MENU:
				Gamemanager::menu::UpdateMenu(GameWindow);
				Gamemanager::menu::DrawMenu(GameWindow);
				break;
			case GameManager::GAMEPLAY:

				GameManager::Gameplay::UpdateFrog(GameWindow, event);

				GameManager::Gameplay::UpdateCar(GameWindow, event);
				GameManager::Gameplay::Draw(GameWindow);
				break;
			case GameManager::GAMEOVER:
				break;
			case GameManager::CREDITS:
				break;
			case GameManager::PAUSE:
				break;
			default:
				break;
			}

			GameWindow.display();
		}
	}

	void ExecuteGame()
	{
		InitGame();
		while (true)
		{
			GameManager();
		}
	}
}
