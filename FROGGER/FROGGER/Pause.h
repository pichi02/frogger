#pragma once
#include<SFML/Graphics.hpp>
namespace GameManager
{
	namespace Pause
	{
		void InitPause();
		void UpdatePause(sf::RenderWindow& rWindow);
		void DrawPause(sf::RenderWindow& window);
		void UnloadPause();
	}
}