
#include "GameManager.h"
#include"Frog.h"
#include"Car.h"
#include "Menu.h"
#include "Gameplay.h"
#include"GameOver.h"
#include"Credits.h"

namespace GameManager
{
	using namespace Gameplay;
	int screenWidth = 800;
	int screenHeight = 600;
	bool isOpen = true;
	extern screens currentScreen = MENU;

	void InitGame()
	{
		GameManager::Menu::InitMenu();
		GameManager::GameOver::InitGameOver();
		GameManager::Credits::InitCredits();
	}
	
	void GameManager()
	{
		sf::RenderWindow GameWindow(sf::VideoMode(GameManager::screenWidth, GameManager::screenHeight), "FROGGER");

		while (isOpen)
		{
			sf::Event event;


			GameWindow.clear();
			switch (currentScreen)
			{
			case GameManager::MENU:
				GameManager::Menu::UpdateMenu(GameWindow);
				GameManager::Menu::DrawMenu(GameWindow);
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
				GameManager::GameOver::UpdateGameOver(GameWindow);
				GameManager::GameOver::DrawGameOver(GameWindow);
				break;

			case GameManager::CREDITS:
				GameManager::Credits::UpdateCredits(GameWindow);
				GameManager::Credits::DrawCredits(GameWindow);
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
