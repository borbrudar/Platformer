#include "World.h"

void World::loadWorld()
{
	for (int x = 0; x < level.getSize().x; x++) {
		for (int y = 0; y < level.getSize().y; y++) {
			if (level.getPixel(x, y) == Color(255, 0, 0)) {
				addBlock(x, y);
				blocks[blocks.size() - 1].type = type::stone;
			}
			if (level.getPixel(x, y) == Color(0, 255, 0)) {
				addBlock(x, y);
				blocks[blocks.size() - 1].type = type::dirt;
			}
			if (level.getPixel(x, y) == Color(0, 0, 255)) {
				addEnemy(x, y);
			}
		}
	}

	for (int i = 0; i < blocks.size(); i++) {
		blocks[i].loadBlock(tex.texture[(int)blocks[i].type]);
	}
	for (int i = 0; i < enemies.size(); i++) {
		enemies[i].loadEnemy(tex.texture[2]);
	}
}

void World::addBlock(int x, int y)
{
	blocks.push_back(Block(x,y,size));
	blocks[blocks.size() - 1].setPosition(x * size, y * size);
}

void World::addEnemy(int x, int y)
{
	enemies.push_back(Enemy(x,y,size));
	enemies[enemies.size() - 1].setPosition(x * size, y * size);
}

void World::updateWorld(bool right, bool left, bool up)
{
	boxes.clear();
	boxes.resize(blocks.size() + enemies.size());
	for (int i = 0; i < blocks.size(); i++) boxes.push_back(blocks[i].box);
	for (int i = 0; i < enemies.size(); i++) boxes.push_back(enemies[i].box);

	int type = player.updatePlayer(boxes, up);

	//block if in the way
	amount = 1.5;
	if (type == 2) amount = 0;
	if (type == 3) amount = 0;
	if (type == 2 && right) amount = 1.5f;
	if (type == 3 && left) amount = 1.5f;
	
	
	//update blocks
	for (int i = 0; i < blocks.size(); i++) blocks[i].updateBlock(right, left, amount);
	for (int i = 0; i < enemies.size(); i++) enemies[i].updateEnemy(right, left, amount);
}

void World::drawWorld(sf::RenderWindow & window)
{
	for(int i = 0; i < blocks.size();i++) blocks[i].drawBlock(window);
	for (int i = 0; i < enemies.size(); i++) enemies[i].drawEnemy(window);
	player.drawPlayer(window);
}
