#include "Frog.h"
//#include <SFML/Graphics.hpp>

GameManager::Frog::Frog::Frog(sf::RectangleShape frogShape, Vector2 pos, float speed)
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

sf::RectangleShape GameManager::Frog::Frog::GetFrogShape()
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
void GameManager::Frog::Frog::Draw()
{
	frogShape.setPosition(pos.x, pos.y);
}
bool GameManager::Frog::Frog::Collision(sf::RectangleShape rect)
{
	return frogShape.getPosition().x <= rect.getPosition().x + rect.getSize().x && rect.getPosition().x <= frogShape.getPosition().x + frogShape.getSize().x && frogShape.getPosition().y <= rect.getPosition().y + rect.getSize().y && rect.getPosition().y <= frogShape.getPosition().y + frogShape.getSize().y;
}


