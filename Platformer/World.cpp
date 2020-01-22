#include "World.h"

void World::loadWorld()
{
	for (int x = 0; x < level.getSize().x; x++) {
		for (int y = 0; y < level.getSize().y; y++) {
			if (level.getPixel(x, y) != Color(255, 255, 255)) {
				blocks.push_back(Block());
				blocks[blocks.size() - 1].setPosition(x * 20, y * 20);
				boxes.push_back(BoundingBox());
				boxes[boxes.size() - 1].setPosition(x * 20, y * 20);
				boxes[boxes.size() - 1].setBox(20, 20);

				if (level.getPixel(x, y) == Color(255, 0, 0)) blocks[blocks.size() - 1].type = type::stone;
				if (level.getPixel(x, y) == Color(0, 255, 0)) blocks[blocks.size() - 1].type = type::dirt;
			}
		}
	}

	for (int i = 0; i < blocks.size(); i++) {
		blocks[i].loadBlock(tex.texture[(int)blocks[i].type]);
	}
}

void World::updateWorld(bool right, bool left, bool up)
{
	int type = player.updatePlayer(boxes, up);

	//block if in the way
	amount = 1.5;
	if (type == 2) amount = 0;
	if (type == 3) amount = 0;
	if (type == 2 && right) amount = 1.5f;
	if (type == 3 && left) amount = 1.5f;
	
	
	//update blocks
	for (int i = 0; i < blocks.size(); i++) {
		blocks[i].updateBlock(right, left, amount);
		boxes[i].updateBox(right, left, amount);
	}
	
}

void World::drawWorld(sf::RenderWindow & window)
{
	for(int i = 0; i < blocks.size();i++) blocks[i].drawBlock(window);
	player.drawPlayer(window);
}
