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
			sf::RectangleShape frogShape;
			
			
			
		public:
			Frog(sf::RectangleShape frogShape,Vector2 pos, float speed);
			~Frog();
			
			Vector2 GetPosition();
			float GetSpeed();
			sf::RectangleShape GetFrogShape();
			void MoveUp();

			void MoveDown();

			void MoveLeft();

			void MoveRight();
			void Draw();

			bool Collision(sf::RectangleShape rect);
		
		};

		
	}
}