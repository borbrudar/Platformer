#include "Player.h"

void Player::updatePlayer(std::vector<BoundingBox> boxes)
{
	for (int i = 0; i < boxes.size(); i++) {
		if (box.checkCollision(boxes[i])) {
			touchingGround = 1;
			break;
		}
	}

	if (!touchingGround) vel += acc; else { vel = 0; }
	box.pos.y += vel;
}

void Player::drawPlayer(RenderWindow & window)
{
	shape.setPosition(box.pos);
	window.draw(shape);
}
