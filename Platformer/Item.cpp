#include "Item.h"

void Item::updateItem(Vector2f pos)
{
	sprite.setPosition(pos);
}

void Item::drawItem(RenderWindow & window)
{
	window.draw(sprite);
}

void Item::loadItem(Texture & t)
{
	sprite.setTexture(t);
}

void Item::setPosition(int x, int y)
{
	sprite.setPosition(x, y);
}