#include "Rect.h"

GameManager::Rect::Rect::Rect(sf::RectangleShape rectShape, Vector2 pos, float speed)
{
	this->pos = pos;
	this->rectShape = rectShape;
	this->speed = speed;
}

GameManager::Rect::Rect::Rect(sf::RectangleShape rectShape, Vector2 pos, float speed, std::string textureDirectory)
{
	this->pos = pos;
	this->rectShape = rectShape;
	this->speed = speed;
	this->textureDirectory = textureDirectory;

	texture.loadFromFile(textureDirectory);
	sprite.setTexture(texture);
}

GameManager::Rect::Rect::~Rect()
{
}

Vector2 GameManager::Rect::Rect::GetPos()
{
	return pos;
}

sf::RectangleShape GameManager::Rect::Rect::GetRectShape()
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
	if (pos.x + rectShape.getSize().x < 0)
	{
		pos.x = screenWidth;
	}
	else if (pos.x > screenWidth)
	{
		pos.x = 0;
	}
}

void GameManager::Rect::Rect::SetPos(Vector2 pos)
{
	this->pos = pos;
	rectShape.setPosition(pos.x, pos.y);
}

sf::Texture GameManager::Rect::Rect::GetRectTexture()
{
	return texture;
}

sf::Sprite GameManager::Rect::Rect::GetRectSprite()
{
	return sprite;
}

void GameManager::Rect::Rect::SetSpritePosition(Vector2 pos)
{
	sprite.setPosition({ pos.x, pos.y });
}
