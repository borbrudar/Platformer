#include "Block.h"

void Block::updateBlock(Vector2f pos)
{
	sprite.setPosition(pos);
	
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
