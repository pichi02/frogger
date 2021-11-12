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

void GameManager::Frog::Frog::MoveUp()
{
	pos.y -= speed;
}
void GameManager::Frog::Frog::MoveDown()
{
	pos.y += speed;
}
void GameManager::Frog::Frog::MoveLeft()
{
	pos.x -= speed;
}
void GameManager::Frog::Frog::MoveRight()
{
	pos.x += speed;
}
void  GameManager::Frog::Frog::Draw()
{
	frogShape.setPosition(pos.x, pos.y);
}

