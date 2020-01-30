#include "BoundingBox.h"

BoundingBox::BoundingBox(int x, int y, int size)
{
	setPosition(x * size, y * size);
	setBox(size, size);
}

void BoundingBox::updateBox(int amount)
{
	pos.x += amount;
}

void BoundingBox::updateBox(int amount, std::vector<BoundingBox> boxes)
{
	touchingGround = 0;
	int type;
	for (int i = 0; i < boxes.size(); i++) {
		if (i != id) {
			if (type = boxes[id].checkCollision(boxes[i])) {
				pos.y -= pos.y - boxes[i].pos.y + boxes[i].width;
				if (type == 1) touchingGround = 1;
				break;
			}
		}
	}

	pos.x += amount;
	pos.x -= 0.3f;

	if (pos.y > (600 - height - 1)) touchingGround = true;

	if (!touchingGround) vel += acc;
	else vel = 0;

	pos.y += vel;
	if (pos.y > (600 - height)) pos.y = 600 - height;
}

int BoundingBox::updateBox(std::vector<BoundingBox> boxes, Sprite &sprite, Animation &ani)
{
	touchingGround = 0;
	int type = 0;

	for (int i = 0; i < boxes.size(); i++) {
		if (boxes[i].id != id) {
			if (type = checkCollision(boxes[i])) {
				/*if (boxes[i].type == type::enemy) {
					shape.setFillColor(Color::Red);
					break;
				}
				else shape.setFillColor(Color::Blue);*/
				if (type == 1) {
					pos.y -= pos.y - boxes[i].pos.y + boxes[i].width;
					touchingGround = 1;
					sprite.setTexture(ani.textures[0]);
				}
				else if (type == 2) vel = acc;
				break;
			}
		}
	}

	if (pos.y > (600 - height - 1)) touchingGround = true;

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

	pos.y += vel;
	if (pos.y > (600 - height)) pos.y = 600 - height;

	return type;
}


void BoundingBox::setBox(int width, int height)
{
	this->width = width;
	this->height = height;
}

void BoundingBox::setPosition(int x, int y)
{
	pos.x = x;
	pos.y = y;
}

int BoundingBox::checkCollision(BoundingBox box)
{
	int col = 0;
	if ((pos.x < (box.pos.x + width)) && ((pos.x + width) > (box.pos.x)) && (pos.y < (box.pos.y + height)) && ((pos.y + height) > (box.pos.y))) col = 1;

	//update position (move later)
	if (col) {
		if (pos.y <= box.pos.y) {
			col = 1;
		}
		else { 
			col = 2;
		}
	}
	return col;
}
