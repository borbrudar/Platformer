#include "Block.h"

void Block::updateBlock(bool right, bool left, int amount)
{
	if (right) sprite.move(Vector2f(amount, 0));
	else if (left) sprite.move(Vector2f(-amount, 0));
}

void Block::loadBlock(Texture & t)
{ 
	sprite.setTexture(t);
	sprite.setScale(0.25, 0.25);
}

void Block::setPosition(int x, int y)
{
	sprite.setPosition(x, y);
}

void Block::drawBlock(RenderWindow & window)
{
	window.draw(sprite);
}
