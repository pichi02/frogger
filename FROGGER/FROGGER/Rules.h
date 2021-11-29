#pragma once
#include<SFML/Graphics.hpp>
namespace GameManager
{
	namespace Rules
	{
		void InitRules();
		void UpdateRules(sf::RenderWindow& rWindow);
		void DrawRules(sf::RenderWindow& window);
		void UnloadRules();
	}
}