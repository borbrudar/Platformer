#include "Player.h"

int Player::updatePlayer(std::vector<BoundingBox> boxes, bool jumped)
{
	touchingGround = 0;
	int type = 0;

	for (int i = 0; i < boxes.size(); i++) {
		if (type = box.checkCollision(boxes[i])) {
			touchingGround = 1;
			break;
		}
	}
	if (box.pos.y > 579) touchingGround = true;
	
	if (!touchingGround) vel += acc;
	else vel = 0; 
	if (touchingGround && jumped) vel = -jumpVel;

	box.pos.y += vel;
	if (box.pos.y > (600 - box.height)) box.pos.y = 600 - box.height;

	return type;
}

void Player::drawPlayer(RenderWindow & window)
{
	shape.setPosition(box.pos);
	window.draw(shape);
}
