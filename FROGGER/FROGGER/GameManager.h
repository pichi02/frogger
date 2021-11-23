#pragma once

namespace GameManager
{
	enum screens {MENU, GAMEPLAY, GAMEOVER, CREDITS, PAUSE};

	extern screens currentScreen;

	extern int screenWidth;
	extern int screenHeight;
	void InitGame();
	void GameManager();
	void ExecuteGame();
}
