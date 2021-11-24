#include "Car.h"

GameManager::Rect::Rect::Rect(sf::RectangleShape rectShape, Vector2 pos, float speed)
{
	this->pos = pos;
	this->rectShape = rectShape;
	this->speed = speed;
}

GameManager::Rect::Rect::~Rect()
{
}

Vector2 GameManager::Rect::Rect::GetPos()
{
	return pos;
}

sf::RectangleShape GameManager::Rect::Rect::GetCarShape()
{
	return rectShape;
}

float GameManager::Rect::Rect::GetSpeed()
{
	return speed;
}

void GameManager::Rect::Rect::Move(int screenWidth)
{
	rectShape.setPosition(pos.x, pos.y);
	pos.x -= speed;
	if (pos.x+rectShape.getSize().x<0)
	{
		pos.x = screenWidth;
	}
	else if (pos.x> screenWidth)
	{
		pos.x = 0;
	}
}

void GameManager::Rect::Rect::SetPos(Vector2 pos)
{
	this->pos=pos;
}
