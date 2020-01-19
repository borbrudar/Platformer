#pragma once
#include <SFML/Graphics.hpp>
#include "UTexture.h"
#include "Block.h"
#include "Player.h"
#include <vector>

class World {
public:
	World() {
		level.loadFromFile("textures/level.png");
		loadWorld();
	}
//functions
	void updateWorld(bool moved, bool right);
	void drawWorld(sf::RenderWindow &window);
private:
	void loadWorld();
//variables	
	Player player;
	std::vector<Block> blocks;
	std::vector<BoundingBox> boxes;
	UTexture tex;
	int amount = 1;
	sf::Image level;
};