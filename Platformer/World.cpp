#include "World.h"

void World::loadWorld()
{
	int id = 0;
	for (int x = 0; x < level.getSize().x; x++) {
		for (int y = 0; y < level.getSize().y; y++) {
			if (level.getPixel(x, y) == Color(255, 0, 0)) {
				addEntity(x, y, id, entity_type::block);
				entities[entities.size() - 1].blockType = block_type::stone;
			}
			if (level.getPixel(x, y) == Color(0, 255, 0)) {
				addEntity(x, y, id, entity_type::block);
				entities[entities.size() - 1].blockType = block_type::dirt;
			}
			if (level.getPixel(x, y) == Color(0, 0, 0)) {
				playerID = id;
				addEntity(x, y, id, entity_type::player);
				player.sprite.setPosition(x * size, y * size);
			}
			if (level.getPixel(x, y) == Color(0, 0, 255)) addEntity(x, y, id, entity_type::enemy);
			if (level.getPixel(x, y) == Color(255, 0, 255)) addEntity(x, y, id, entity_type::item);
		}
	}

	for (int i = 0; i < entities.size(); i++) {
		if (entities[i].type == entity_type::block) {
			if (entities[i].blockType == block_type::stone) entities[i].loadEntity(tex.texture[0], 0.5, 0.5);
			if (entities[i].blockType == block_type::dirt) entities[i].loadEntity(tex.texture[1], 0.5, 0.5);
		}
		if (entities[i].type == entity_type::enemy)  entities[i].loadEntity(tex.texture[2], 0.5, 0.5);
		if (entities[i].type == entity_type::item)  entities[i].loadEntity(tex.texture[3]);
	}
}


void World::addEntity(int x, int y, int &id, entity_type type1)
{
	entities.push_back(Entity(type1));
	entities[entities.size() - 1].updateEntity(Vector2f(x * size, y * size));
	entities[entities.size() - 1].id = id;
	boxes.push_back(BoundingBox(x, y, size));
	boxes[boxes.size() - 1].type = (type)type1;
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
	for (int i = 0; i < entities.size(); i++) entities[i].updateEntity(boxes[entities[i].id].pos);
	player.updatePlayer(boxes[playerID].pos);	
}

void World::drawWorld(sf::RenderWindow & window)
{
	for (int i = 0; i < entities.size(); i++) entities[i].drawEntity(window);
	player.drawPlayer(window);
}
