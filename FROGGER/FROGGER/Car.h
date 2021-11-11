#pragma once
#include <SFML/Graphics.hpp>
#include"Vector2.h"
namespace GameManager
{
	namespace Car 
	{

		class Car
		{
		private:
			Vector2 pos;
			sf::RectangleShape carShape;
			float speed;
		public:
			Car(sf::RectangleShape carShape,Vector2 pos, float speed);
			~Car(); 
			Vector2 GetPos();
			sf::RectangleShape GetCarShape();
			float GetSpeed();
			void Move(int screenWidth);


		};

		
	}
}