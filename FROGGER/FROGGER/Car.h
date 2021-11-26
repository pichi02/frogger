#pragma once
#include <SFML/Graphics.hpp>
#include"Vector2.h"
namespace GameManager
{
	namespace Rect 
	{

		class Rect
		{
		private:
			Vector2 pos;
			sf::RectangleShape rectShape;
			float speed;
		public:
			Rect(sf::RectangleShape rectShape,Vector2 pos, float speed);
			~Rect(); 
			Vector2 GetPos();
			sf::RectangleShape GetRectShape();
			float GetSpeed();
			void Move(int screenWidth);
			void SetPos(Vector2 pos);


		};

		
	}
}