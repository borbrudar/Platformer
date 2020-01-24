#include "Enemy.h"

Enemy::Enemy(int x, int y, int size)
{
	box.setPosition(x * size, y * size);
	box.setBox(size, size);
}

void Enemy::updateEnemy(bool right, bool left, int amount)
{
	if (right) sprite.move(Vector2f(amount,0));
	else if (left) sprite.move(Vector2f(-amount, 0));

	sprite.move(-0.3f, 0);
	box.pos.x -= 0.3f;

	box.updateBox(right, left, amount);
}

void Enemy::drawEnemy(RenderWindow & window)
{
	window.draw(sprite);
}

void Enemy::loadEnemy(Texture & t)
{
	sprite.setTexture(t);
	sprite.setScale(0.25, 0.25);
}

void Enemy::setPosition(int x, int y)
{
	sprite.setPosition(x, y);	
}
