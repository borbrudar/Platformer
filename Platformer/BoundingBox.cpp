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

bool BoundingBox::checkCollision(BoundingBox box)
{
	bool col = 0;
	if ((pos.x < (box.pos.x + width)) && ((pos.x + width) > (box.pos.x)) && (pos.y < (box.pos.y + height)) && ((pos.y + height) > (box.pos.y))) col = true;

	if (col) {
		//pos.x += abs(box.pos.x - pos.x);
		pos.y -= pos.y - box.pos.y + width;
	}
	
	return col;
}
