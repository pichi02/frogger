#include "Menu.h"

namespace Gamemanager
{
	namespace menu
	{
		Menu::Menu(float width, float height)
		{
			/*if (!font.loadFromFile("Fonts/AlexandriaFLF.ttf"))
			{
				std::cout << "No font in here" << std::endl;
			}*/

			//Play
			menu[0].setPosition(400, 200);
			menu[0].setFillColor(sf::Color::White);
			menu[0].setSize({100, 70});

			menu[1].setPosition(400, 300);
			menu[1].setFillColor(sf::Color::White);
			menu[1].setSize({ 100, 70 });

			menu[2].setPosition(400, 400);
			menu[2].setFillColor(sf::Color::White);
			menu[2].setSize({ 100, 70 });

			menu[3].setPosition(400, 500);
			menu[3].setFillColor(sf::Color::White);
			menu[3].setSize({ 100, 70 });
			//mainMenu[0].setFont(font);
			/*mainMenu[0].setFillColor(sf::Color::White);
			mainMenu[0].setString("Play");
			mainMenu[0].setCharacterSize(70);
			mainMenu[0].setPosition(400, 200);
			//Options
			//mainMenu[1].setFont(font);
			mainMenu[1].setFillColor(sf::Color::White);
			mainMenu[1].setString("Options");
			mainMenu[1].setCharacterSize(70);
			mainMenu[1].setPosition(400, 300);
			//Credits
			//mainMenu[2].setFont(font);
			mainMenu[2].setFillColor(sf::Color::White);
			mainMenu[2].setString("Credits");
			mainMenu[2].setCharacterSize(70);
			mainMenu[2].setPosition(400, 400);
			//Exit
			//mainMenu[3].setFont(font);
			mainMenu[3].setFillColor(sf::Color::White);
			mainMenu[3].setString("Credits");
			mainMenu[3].setCharacterSize(70);
			mainMenu[3].setPosition(400, 500);*/

			menuSelected = -1;
		}

		Menu::~Menu()
		{

		}

		void Menu::DrawMenu(sf::RenderWindow& window)
		{
			for (int i = 0; i < max_main_menu; i++)
			{
				window.draw(menu[i]);
			}
		}

		void Menu::MoveUp()
		{
			if (menuSelected - 1 >= 0)
			{
				menu[menuSelected].setFillColor(sf::Color::White);

				menuSelected--;
				if (menuSelected == -1)
				{
					menuSelected = 2;
				}
				menu[menuSelected].setFillColor(sf::Color::Blue);
			}
		}

		void Menu::MoveDown()
		{
			if (menuSelected + 1 <= max_main_menu)
			{
				menu[menuSelected].setFillColor(sf::Color::White);
				menuSelected++;
				if (menuSelected == 4)
				{
					menuSelected = 0;
				}
				menu[menuSelected].setFillColor(sf::Color::Blue);
			}
		}

		int Menu::MenuPressed()
		{
			return menuSelected;
		}
	}
}