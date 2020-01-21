#include "Player.h"

void Player::updatePlayer(std::vector<BoundingBox> boxes, bool jumped)
{
	touchingGround = 0;
	for (int i = 0; i < boxes.size(); i++) {
		if (box.checkCollision(boxes[i])) {
			touchingGround = 1;
			break;
		}
	}
	
	if (!touchingGround) {
		vel += acc;
	}	else {
		vel = 0; 
	}
	if (touchingGround && jumped) {
		vel = -4;
	}

	box.pos.y += vel;
	if (box.pos.y > (600 - box.height)) box.pos.y = 600 - box.height;
}

void Player::drawPlayer(RenderWindow & window)
{
	shape.setPosition(box.pos);
	window.draw(shape);
}
