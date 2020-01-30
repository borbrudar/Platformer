#include "World.h"

void World::loadWorld()
{
	int id = 0;
	for (int x = 0; x < level.getSize().x; x++) {
		for (int y = 0; y < level.getSize().y; y++) {
			if (level.getPixel(x, y) == Color(255, 0, 0)) {
				addBlock(x, y,id);
				blocks[blocks.size() - 1].type = block_type::stone;
			}
			if (level.getPixel(x, y) == Color(0, 255, 0)) {
				addBlock(x, y, id);
				blocks[blocks.size() - 1].type = block_type::dirt;
			}
			if (level.getPixel(x, y) == Color(0, 0, 0)) {
				player.sprite.setPosition(x * size, y * size);
				boxes.push_back(BoundingBox(x, y, size));
				boxes[boxes.size() - 1].type = type::player;
				boxes[boxes.size() - 1].id = id;
				playerID = id;
				id++;
			}
			if (level.getPixel(x, y) == Color(0, 0, 255)) addEnemy(x, y, id);
			if (level.getPixel(x, y) == Color(255, 0, 255)) addItem(x, y, id);
		}
	}

	for (int i = 0; i < blocks.size(); i++) {
		blocks[i].loadBlock(tex.texture[(int)blocks[i].type]);
	}
	for (int i = 0; i < enemies.size(); i++) enemies[i].loadEnemy(tex.texture[2]);
	for (int i = 0; i < items.size(); i++) items[i].loadItem(tex.texture[3]);
}

void World::addBlock(int x, int y, int &id)
{
	blocks.push_back(Block());
	blocks[blocks.size() - 1].setPosition(x * size, y * size);
	boxes.push_back(BoundingBox(x, y, size));
	boxes[boxes.size() - 1].type = type::block;
	blocks[blocks.size() - 1].id = id;
	boxes[boxes.size() - 1].id = id;
	id++;
}

void World::addEnemy(int x, int y, int &id)
{
	enemies.push_back(Enemy());
	enemies[enemies.size() - 1].setPosition(x * size, y * size);
	boxes.push_back(BoundingBox(x, y, size));
	boxes[boxes.size() - 1].type = type::enemy;
	enemies[enemies.size() - 1].id = id;
	boxes[boxes.size() - 1].id = id;
	id++;
}

void World::addItem(int x, int y, int &id)
{
	items.push_back(Item());
	items[items.size() - 1].setPosition(x * size, y * size);
	boxes.push_back(BoundingBox(x, y, size));
	boxes[boxes.size() - 1].type = type::item;
	items[items.size() - 1].id = id;
	boxes[boxes.size() - 1].id = id;
	id++;
}

void World::updateWorld(bool right, bool left, bool up)
{
	if (up) boxes[playerID].jumped = true; else boxes[playerID].jumped = false;
	int type = boxes[playerID].updateBox(boxes, player.sprite, player.ani);

	//block if in the way
	if (right) amount = 1.5f; else if (left) amount = -1.5f; else amount = 0;
	if (type == 2) amount = 0;
	if (type == 3) amount = 0;
	if (type == 2 && right) amount = 1.5f;
	if (type == 3 && left) amount = -1.5f;



	for (int i = 0; i < boxes.size(); i++) {
		if(boxes[i].type == type::block || boxes[i].type == type::item) boxes[i].updateBox(amount);
		if (boxes[i].type == type::enemy) boxes[i].updateBox(amount, boxes);
	}

	//update blocks
	player.updatePlayer(boxes[playerID].pos);
	for (int i = 0; i < entities.size(); i++) entities[i].updateEntity(boxes[entities[i].id].pos);
	//for (int i = 0; i < blocks.size(); i++) blocks[i].updateBlock(boxes[blocks[i].id].pos);
	//for (int i = 0; i < enemies.size(); i++) enemies[i].updateEnemy(boxes[enemies[i].id].pos);
	//for (int i = 0; i < items.size(); i++) items[i].updateItem(boxes[items[i].id].pos);
	
}

void World::drawWorld(sf::RenderWindow & window)
{
	for (int i = 0; i < entities.size(); i++) entities[i].drawEntity(window);
	
	//for(int i = 0; i < blocks.size();i++) blocks[i].drawBlock(window);
	//for (int i = 0; i < enemies.size(); i++) enemies[i].drawEnemy(window);
	//for (int i = 0; i < items.size(); i++) items[i].drawItem(window);
	player.drawPlayer(window);
}
