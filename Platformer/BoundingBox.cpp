#include "BoundingBox.h"

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
		pos.x = box.pos.x - width;
		pos.y = box.pos.y - height;
	}

	return col;
}
