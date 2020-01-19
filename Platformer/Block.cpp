#include "Block.h"

void Block::updateBlock(bool right, int amount)
{
	if (right) shape.move(Vector2f(-amount, 0));
	else shape.move(Vector2f(amount, 0));
}

void Block::loadBlock(Texture & t)
{ 
	sprite.setTexture(t);
	sprite.setScale(0.25, 0.25);
}

void Block::setPosition(int x, int y)
{
	shape.setPosition(x, y);
}

void Block::drawBlock(RenderWindow & window)
{
	sprite.setPosition(shape.getPosition());
	sprite.setRotation(shape.getRotation());
	window.draw(sprite);
}
