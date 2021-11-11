#include "Frog.h"
//#include <SFML/Graphics.hpp>

GameManager::Frog::Frog::Frog(sf::CircleShape frogShape, Position pos)
{
	this->frogShape = frogShape;
	this->pos = pos;

}

Position GameManager::Frog::Frog::GetPosition()
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
		pos.y-=0.1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		pos.x -= 0.1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		pos.y += 0.1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		pos.x += 0.1;
	}
	
}


