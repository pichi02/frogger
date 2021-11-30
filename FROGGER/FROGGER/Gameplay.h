#pragma once
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
namespace GameManager
{
	namespace Gameplay
	{
		void InitValues();
		void Update(sf::RenderWindow &window, sf::Event &event);
		void Draw(sf::RenderWindow& window);
		void UpdateFrogMovement(sf::RenderWindow& window, sf::Event& event);
		void ResetValues();
		void UnloadGameplay();
		bool CheckLogsCollision();
		bool CheckGoalsCollision();
		void playMusic();
		extern int screenWidth;
		extern int screenHeight;
		extern bool win;
		extern bool gameOver;
		extern bool pause;
	
		
	}
}