#pragma once
#include <SFML/Graphics.hpp>
struct Position
{
	float x;
	float y;
};
namespace GameManager 
{
	namespace Frog 
	{
		
		class Frog
		{
		private:
			Position pos;
			float speed;
			sf::CircleShape frogShape;
			
			
			
		public:
			Frog(sf::CircleShape frogShape,Position pos);
			~Frog();
			
			Position GetPosition();
			float GetSpeed();
			sf::CircleShape GetFrogShape();
			void Move(sf::RenderWindow& window);
		
		};

		
	}
}