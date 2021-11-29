#pragma once
#include<SFML/Graphics.hpp>
namespace GameManager
{
	namespace GameOver
	{
		void InitGameOver();
		void UpdateGameOver(sf::RenderWindow& rWindow);
		void DrawGameOver(sf::RenderWindow& window);
		void UnloadGameOver();
	}
}