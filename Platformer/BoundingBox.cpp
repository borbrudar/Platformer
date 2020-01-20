#include "BoundingBox.h"

void BoundingBox::updateBox(int right, int amount)
{
	if (right == 1) pos.x += amount;
	else if (right == 2) pos.x += -amount;
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
		//pos.y -= (box.pos.y - pos.y);
	}
	
	return col;
}
