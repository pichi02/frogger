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

			int goalsCollected;
			int lifes;
			Vector2 pos;
			float speed;
			sf::RectangleShape frogShape;

			sf::Sprite frogSprite;
			sf::Texture frogTexture;

		public:
			Frog(sf::RectangleShape frogShape, Vector2 pos, float speed);
			~Frog();

			Vector2 GetPosition();
			float GetSpeed();
			sf::RectangleShape GetFrogShape();
			void MoveUp();

			void MoveDown();
			int GetLifes();
			void MoveLeft();
			void MoveRight();
			void SetShapePosition();
			void SetPosition(Vector2 pos);
			bool Collision(sf::RectangleShape rect);
			void SubstractLife();
			void IncreaseGoalsCollected();
			int GetCollectedGoals();
			sf::Texture GetFrogTexture();
			sf::Sprite GetFrogSprite();
			void SetSpritePosition(Vector2 pos);
			void CheckWallCollision(int width, int height);
		};
	}
}