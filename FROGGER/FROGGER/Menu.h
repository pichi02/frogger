#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>

namespace Gamemanager
{
	namespace menu
	{
		void InitMenu();
		void UpdateMenu(sf::RenderWindow& rWindow);
		void DrawMenu(sf::RenderWindow& window);
		void UnloadMenu();
	}
}