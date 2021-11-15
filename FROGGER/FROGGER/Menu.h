#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>

namespace Gamemanager
{
	namespace menu
	{
		#define max_main_menu 4

		class Menu
		{
		private:
			int menuSelected;
			//sf::Font font;
			//sf::Text mainMenu[max_main_menu];
			sf::RectangleShape menu[max_main_menu];
		public:
			Menu(float width, float height);
			~Menu();

			void DrawMenu(sf::RenderWindow& window);
			void MoveUp();
			void MoveDown();

			int MenuPressed();
		};
	}
}