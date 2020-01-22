#include "BoundingBox.h"

void BoundingBox::updateBox(bool right, bool left, int amount)
{
	if (right) pos.x += amount;
	else if (left) pos.x += -amount;
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
			pos.y -= pos.y - box.pos.y + width;
		}
	}
	
	return col;
}
