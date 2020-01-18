#pragma once
#include <SFML/Graphics.hpp>
#include "UTexture.h"
#include "Block.h"
#include <vector>

class World {
public:
	World() {
		level.loadFromFile("textures/level.png");
		loadWorld();
	}
	void loadWorld();
	void updateWorld(bool moved, bool right);
	void drawWorld(sf::RenderWindow &window);
	std::vector<Block> blocks;
	UTexture tex;
	int amount = 1;
	sf::Image level;
};