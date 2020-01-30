#include "Entity.h"

void Entity::loadEntity(Texture & t, int x, int y)
{
	sprite.setTexture(t);
	sprite.setScale(x, y);
}

void Entity::updateEntity(Vector2f pos)
{
	sprite.setPosition(pos);
}

void Entity::drawEntity(RenderWindow & window)
{
	window.draw(sprite);
}
