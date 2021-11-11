#include "Frog.h"
//#include <SFML/Graphics.hpp>

GameManager::Frog::Frog::Frog(sf::CircleShape frogShape, Vector2 pos, float speed)
{
	this->frogShape = frogShape;
	this->pos = pos;
	this->speed = speed;

}

Vector2 GameManager::Frog::Frog::GetPosition()
{
	return pos;
}

float GameManager::Frog::Frog::GetSpeed()
{
	return speed;
}

sf::CircleShape GameManager::Frog::Frog::GetFrogShape()
{
	return frogShape;
}

void GameManager::Frog::Frog::Move(sf::RenderWindow& window)
{
	frogShape.setPosition(pos.x, pos.y);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		pos.y-=speed;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		pos.x -= speed;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		pos.y += speed;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		pos.x += speed;
	}
	
}


