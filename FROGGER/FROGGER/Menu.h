#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>

namespace GameManager
{
	namespace Menu
	{
		void InitMenu();
		void UpdateMenu(sf::RenderWindow& rWindow);
		void DrawMenu(sf::RenderWindow& window);
		void UnloadMenu();
	}
}