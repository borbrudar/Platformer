#include "World.h"

void World::loadWorld()
{
	for (int x = 0; x < 40; x++) {
		for (int y = 0; y < 30; y++) {
			if (level.getPixel(x, y) == Color(255, 0, 0)) {
				blocks.push_back(Block());
				blocks[blocks.size() - 1].setPosition(x * 20, y * 20);
			}
		}
	}

	for (int i = 0; i < blocks.size(); i++) {
		blocks[i].loadBlock(tex.texture);
	}
}

void World::updateWorld(bool moved, bool right)
{
	for (int i = 0; i < blocks.size(); i++) blocks[i].updateBlock(moved, right, amount);
}

void World::drawWorld(sf::RenderWindow & window)
{
	for(int i = 0; i < blocks.size();i++) blocks[i].drawBlock(window);
}
