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
	bool isOpen = true;
	screens currentScreen = MENU;

	void InitGame()
	{
		GameManager::Gameplay::InitValues();
		Gamemanager::menu::InitMenu();
	}

	void GameManager()
	{
		sf::RenderWindow GameWindow(sf::VideoMode(GameManager::screenWidth, GameManager::screenHeight), "FROGGER");

		while (isOpen && !gameOver)
		{
			sf::Event event;


			GameWindow.clear();
			switch (currentScreen)
			{
			case GameManager::MENU:
				Gamemanager::menu::UpdateMenu(GameWindow);
				Gamemanager::menu::DrawMenu(GameWindow);
				break;
			case GameManager::GAMEPLAY:
				if (GameWindow.pollEvent(event))
				{
					GameManager::Gameplay::UpdateFrog(GameWindow, event);
					if (event.type == sf::Event::Closed)
					{
						isOpen = false;

					}
				}

				GameManager::Gameplay::UpdateRects(GameWindow, event);
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

		GameManager();

	}
}
