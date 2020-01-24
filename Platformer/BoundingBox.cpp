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

void BoundingBox::updateBox(int amount, bool &touchingGround, int vel)
{
	if (pos.y > 579) touchingGround = true;

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
			pos.y -= pos.y - box.pos.y + width;
		}
	}
	
	return col;
}
