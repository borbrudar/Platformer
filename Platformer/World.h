#pragma once
#include <SFML/Graphics.hpp>
#include "UTexture.h"
#include "Block.h"
#include "Player.h"
#include "Enemy.h"
#include "Item.h"
#include "Entity.h"
#include <vector>

class World {
public:
	World() {
		level.loadFromFile("textures/level.png");
		loadWorld();
	}
//functions
	void updateWorld(bool right, bool left, bool up);
	void drawWorld(sf::RenderWindow &window);
private:
	void loadWorld();
	void addEntity(int x, int y, int &id, entity_type type1);
//variables	
	Player player;
	std::vector<BoundingBox> boxes;
	std::vector<Entity> entities;
	UTexture tex;
	int amount = 1.5;
	sf::Image level;
	int size = 40;
	unsigned int playerID;
};