#include "Block.h"

void Block::updateBlock(int amount)
{
	sprite.move(Vector2f(amount, 0));
	
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
