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
				if (type == 4) boxes[id].pos.y -= boxes[id].pos.y - boxes[i].pos.y + boxes[i].width;
				touchingGround = 1;
				break;
			}
		}
	}

	pos.x += amount;
	pos.x -= 0.3f;

	if (pos.y > 579) touchingGround = true;

	if (!touchingGround) vel += acc;
	else vel = 0;

	pos.y += vel;
	if (pos.y > (600 - height)) pos.y = 600 - height;
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
		if (pos.y >= box.pos.y) {
			if (pos.x <= box.pos.x) col = 2;
			else col = 3;
		}
		else {
			col = 4;
		}
	}
	
	return col;
}
