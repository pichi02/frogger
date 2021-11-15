#include <SFML/Graphics.hpp>
#include"GameManager.h"
//#include"Gameplay.h"
//#include"Frog.h"
//#include"Car.h"
#include"Menu.h"

using namespace Gamemanager::menu;

namespace GameManager
{
	void GameManager()
	{
		int screenWidth = 800;
		int screenHeight = 600;
		float speedVariation = 0.05f;
		const int carsCount = 4;
		bool gameOver = false;
		sf::RenderWindow MENU(sf::VideoMode(screenWidth, screenHeight), "FROGGER");
		Menu menu(MENU.getSize().x, MENU.getSize().y);

		while (MENU.isOpen())
		{
			sf::Event event;
			while (MENU.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					MENU.close();
				}

				if (event.type == sf::Event::KeyReleased)
				{
					if (event.key.code == sf::Keyboard::Up)
					{
						menu.MoveUp();
						break;
					}

					if (event.key.code == sf::Keyboard::Down)
					{
						menu.MoveDown();
						break;
					}

					if (event.key.code == sf::Keyboard::Return)
					{
						sf::RenderWindow Play(sf::VideoMode(800, 600), "Frogger");
						sf::RenderWindow Options(sf::VideoMode(800, 600), "Options");
						sf::RenderWindow Credits(sf::VideoMode(800, 600), "Credits");

						int x = menu.MenuPressed();

						if (x == 0)
						{
							while (Play.isOpen())
							{
								sf::Event aEvent;
								while (Play.pollEvent(aEvent))
								{
									if (aEvent.type == sf::Event::Closed)
									{
										Play.close();
									}

									if (aEvent.type == sf::Event::KeyPressed)
									{
										if (aEvent.key.code == sf::Keyboard::Escape)
										{
											Play.close();
										}
									}
								}

								Options.close();
								Credits.close();
								Play.clear();
								Play.display();
							}
						}

						if (x == 1)
						{
							while (Options.isOpen())
							{
								sf::Event aEvent;
								while (Options.pollEvent(aEvent))
								{
									if (aEvent.type == sf::Event::Closed)
									{
										Options.close();
									}

									if (aEvent.type == sf::Event::KeyPressed)
									{
										if (aEvent.key.code == sf::Keyboard::Escape)
										{
											Options.close();
										}
									}
								}

								Play.close();
								Options.close();
								Credits.close();
								Options.display();
							}
						}

						if (x == 2)
						{
							while (Credits.isOpen())
							{
								sf::Event aEvent;
								while (Credits.pollEvent(aEvent))
								{
									if (aEvent.type == sf::Event::Closed)
									{
										Options.close();
									}

									if (aEvent.type == sf::Event::KeyPressed)
									{
										if (aEvent.key.code == sf::Keyboard::Escape)
										{
											Options.close();
										}
									}
								}

								Play.close();
								Options.close();
								Credits.close();
								Credits.display();
							}
						}

						if (x == 3)
						{
							MENU.close();
							break;
						}
					}
				}
			}

			MENU.clear();
			menu.DrawMenu(MENU);
			MENU.display();
		}






















		/*sf::RectangleShape frogRect({18.0f,18.0f});
		sf::RectangleShape rect({ 40.0f ,17.0f });
		frogRect.setFillColor(sf::Color::Green);
		rect.setFillColor(sf::Color::Blue);
		Frog::Frog* frog = new Frog::Frog(frogRect, { screenWidth / 2 -frogRect.getSize().x/2,screenHeight * 0.87f }, 30.3f);
		Car::Car* car[carsCount]; //= new Car::Car(rect, { screenWidth / 2.0f, screenHeight/2.0f }, 0.15);
		for (int i = 0; i < carsCount; i++)
		{
			if (i%2==0)
			{
				car[i] = new Car::Car(rect, { screenWidth / 2.0f, screenHeight / 1.5f + i * screenHeight * 0.05f }, 0.15+i*speedVariation );
			}
			else
			{
				car[i] = new Car::Car(rect, { screenWidth / 2.0f, screenHeight / 1.5f + i * screenHeight * 0.05f }, -0.15 - i * speedVariation);
			}
			
		}


		while (MENU.isOpen()&&!gameOver)
		{
			sf::Event event;
			while (MENU.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					MENU.close();

				switch (event.type)
				{
				case sf::Event::KeyReleased:
					switch (event.key.code)
					{
					case sf::Keyboard::W:
						frog->MoveUp();
						break;
					case sf::Keyboard::A:
						frog->MoveLeft();
						break;
					case sf::Keyboard::S:
						frog->MoveDown();
						break;
					case sf::Keyboard::D:
						frog->MoveRight();
						break;
					default:
						break;
					}
				default:
					break;
				}

			}
			MENU.clear();

			for (int i = 0; i < carsCount; i++)
			{
				car[i]->Move(screenWidth);
				MENU.draw(car[i]->GetCarShape());
				if (frog->Collision(car[i]->GetCarShape()))
				{
					gameOver = true;
				}
				

			}

			frog->Draw();
			MENU.draw(frog->GetFrogShape());

			MENU.display();

		}*/

	
	}
}
