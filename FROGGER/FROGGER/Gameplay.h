#pragma once
#include <SFML/Graphics.hpp>

namespace GameManager
{
	namespace Gameplay
	{
		void InitValues();
		void UpdateRects(sf::RenderWindow &window, sf::Event &event);
		void Draw(sf::RenderWindow& window);
		void UpdateFrog(sf::RenderWindow& window, sf::Event& event);
		void ResetValues();
		void UnloadGameplay();
		bool CheckLogsCollision();
		bool CheckGoalsCollision();
		extern int screenWidth;
		extern int screenHeight;
		extern bool win;
		extern bool gameOver;
		extern bool pause;
	}
}