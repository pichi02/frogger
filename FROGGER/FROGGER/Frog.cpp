#include "Frog.h"
//#include <SFML/Graphics.hpp>

GameManager::Frog::Frog::Frog(sf::RectangleShape frogShape, Vector2 pos, float speed)
{
	this->frogShape = frogShape;
	this->pos = pos;
	this->speed = speed;
	lifes = 5;
	goalsCollected = 0;

	frogTexture.loadFromFile("Textures/frog.png");
	frogSprite.setTexture(frogTexture);
}

GameManager::Frog::Frog::~Frog()
{

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
int GameManager::Frog::Frog::GetLifes()
{
	return lifes;
}
void GameManager::Frog::Frog::MoveLeft()
{
	pos.x -= speed;
}
void GameManager::Frog::Frog::MoveRight()
{
	pos.x += speed;
}
void GameManager::Frog::Frog::SetShapePosition()
{
	frogShape.setPosition(pos.x, pos.y);
}
void GameManager::Frog::Frog::SetPosition(Vector2 pos)
{
	this->pos = pos;
}
bool GameManager::Frog::Frog::Collision(sf::RectangleShape rect)
{
	return pos.x <= rect.getPosition().x + rect.getSize().x
		&& rect.getPosition().x <= pos.x + frogShape.getSize().x
		&& pos.y <= rect.getPosition().y + rect.getSize().y
		&& rect.getPosition().y <= pos.y + frogShape.getSize().y;

}

void GameManager::Frog::Frog::SubstractLife()
{
	lifes--;
}

void GameManager::Frog::Frog::IncreaseGoalsCollected()
{
	goalsCollected++;
}

int GameManager::Frog::Frog::GetCollectedGoals()
{
	return goalsCollected;
}

sf::Texture GameManager::Frog::Frog::GetFrogTexture()
{
	return frogTexture;
}

sf::Sprite GameManager::Frog::Frog::GetFrogSprite()
{
	return frogSprite;
}

void GameManager::Frog::Frog::SetSpritePosition(Vector2 pos)
{
	frogSprite.setPosition({ pos.x, pos.y });
}

void GameManager::Frog::Frog::CheckWallCollision(int width, int height)
{
	if (pos.x >= width)
	{
		pos.x = width - frogShape.getSize().x;
	}
	else if (pos.x <= 0 - frogShape.getSize().x)
	{
		pos.x = 0;
	}
	if (pos.y >= height)
	{
		pos.y = height - frogShape.getSize().y;
	}
}




