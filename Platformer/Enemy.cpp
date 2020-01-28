#include "Enemy.h"

void Enemy::updateEnemy(Vector2f pos)
{
	sprite.setPosition(pos);
}

void Enemy::drawEnemy(RenderWindow & window)
{
	window.draw(sprite);
}

void Enemy::loadEnemy(Texture & t)
{
	sprite.setTexture(t);
	sprite.setScale(0.5, 0.5);
}

void Enemy::setPosition(int x, int y)
{
	sprite.setPosition(x, y);	
}
