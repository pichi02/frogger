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
			sf::Sprite sprite;
			sf::Texture texture;
			std::string textureDirectory;
		public:
			Rect(sf::RectangleShape rectShape, Vector2 pos, float speed);
			Rect(sf::RectangleShape rectShape, Vector2 pos, float speed, std::string textureDirectory);
			~Rect();
			Vector2 GetPos();
			sf::RectangleShape GetRectShape();
			float GetSpeed();
			void Move(int screenWidth);
			void SetPos(Vector2 pos);
			sf::Texture GetRectTexture();
			sf::Sprite GetRectSprite();
			void SetSpritePosition(Vector2 pos);
		};
	}
}