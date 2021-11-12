#include "Car.h"

GameManager::Car::Car::Car(sf::RectangleShape carShape, Vector2 pos, float speed)
{
	this->pos = pos;
	this->carShape = carShape;
	this->speed = speed;
}

Vector2 GameManager::Car::Car::GetPos()
{
	return pos;
}

sf::RectangleShape GameManager::Car::Car::GetCarShape()
{
	return carShape;
}

float GameManager::Car::Car::GetSpeed()
{
	return speed;
}

void GameManager::Car::Car::Move(int screenWidth)
{
	carShape.setPosition(pos.x, pos.y);
	pos.x -= speed;
	if (pos.x+carShape.getSize().x<0)
	{
		pos.x = screenWidth;
	}
	else if (pos.x> screenWidth)
	{
		pos.x = 0;
	}
}
