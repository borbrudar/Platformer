#include "Player.h"

int Player::updatePlayer(std::vector<BoundingBox> boxes, bool jumped)
{
	touchingGround = 0;
	int type = 0;

	for (int i = 0; i < boxes.size(); i++) {
		if (type = box.checkCollision(boxes[i])) {
			
			/*if (boxes[i].type == type::enemy) {
				shape.setFillColor(Color::Red);
				break;
			}
			else shape.setFillColor(Color::Blue);*/
			if (type == 1) {
				box.pos.y -= box.pos.y - boxes[i].pos.y + boxes[i].width;
				touchingGround = 1;
				sprite.setTexture(ani.textures[0]);
			}
			else if (type == 2) vel = acc;
			break;
		}
	}
	
	if (box.pos.y > (600 - size - 1)) touchingGround = true;

	if (!touchingGround) {
		vel += acc;
		sprite.setTexture(ani.textures[2]);
	}
	else vel = 0; 

	if (touchingGround && jumped) {
		vel = -jumpVel; 
		sprite.setTexture(ani.textures[1]);
	}
	if (!jumped) sprite.setTexture(ani.textures[0]);

	box.pos.y += vel;
	if (box.pos.y > (600 - box.height)) box.pos.y = 600 - box.height;

	return type;
}

void Player::drawPlayer(RenderWindow & window)
{
	sprite.setPosition(box.pos);
	window.draw(sprite);
}
