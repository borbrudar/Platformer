#include "Player.h"

void Player::updatePlayer(std::vector<BoundingBox> boxes)
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
		box.pos.y += vel;
	}	else {
		vel = 0; 
	}
}

void Player::drawPlayer(RenderWindow & window)
{
	shape.setPosition(box.pos);
	window.draw(shape);
}
