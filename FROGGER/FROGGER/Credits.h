#pragma once
#include<SFML/Graphics.hpp>
namespace GameManager
{
	namespace Credits
	{
		void InitCredits();
		void UpdateCredits(sf::RenderWindow& rWindow);
		void DrawCredits(sf::RenderWindow& window);
		
	}
}