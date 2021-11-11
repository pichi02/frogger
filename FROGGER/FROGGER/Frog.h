#pragma once
#include <SFML/Graphics.hpp>
#include"Vector2.h"
namespace GameManager 
{
	namespace Frog 
	{
		
		class Frog
		{
		private:
			Vector2 pos;
			float speed;
			sf::CircleShape frogShape;
			
			
			
		public:
			Frog(sf::CircleShape frogShape,Vector2 pos, float speed);
			~Frog();
			
			Vector2 GetPosition();
			float GetSpeed();
			sf::CircleShape GetFrogShape();
			void Move(sf::RenderWindow& window);
		
		};

		
	}
}