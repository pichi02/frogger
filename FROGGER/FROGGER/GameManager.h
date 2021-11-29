#pragma once
#include <SFML/Graphics.hpp>
namespace GameManager
{
	enum screens { MENU, GAMEPLAY, GAMEOVER, CREDITS, PAUSE};

	extern screens currentScreen;

	extern int screenWidth;
	extern int screenHeight;
	extern bool isOpen;
	void InitGame();
	void GameManager();
	void ExecuteGame();
}
