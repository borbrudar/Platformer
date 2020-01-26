#include "Player.h"

int Player::updatePlayer(std::vector<BoundingBox> boxes, bool jumped)
{
	touchingGround = 0;
	int type = 0;

	for (int i = 0; i < boxes.size(); i++) {
		if (type = box.checkCollision(boxes[i])) {
			if (type == 2) {
				box.pos.y -= box.pos.y - boxes[i].pos.y + boxes[i].width;
				touchingGround = 1;
			}
			else { 
				box.pos.y += box.pos.y - boxes[i].pos.y; 
				vel = 0;
			}
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
