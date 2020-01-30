#include "Player.h"

void Player::updatePlayer(Vector2f pos)
{
	sprite.setPosition(pos);
}

void Player::drawPlayer(RenderWindow & window)
{
	window.draw(sprite);
}
