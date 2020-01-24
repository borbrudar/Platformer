#pragma once
#include <SFML/Graphics.hpp>
#include "UTexture.h"
#include "Block.h"
#include "Player.h"
#include "Enemy.h"
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
	void addBlock(int x, int y);
	void addPlayer(int x, int y);
	void addEnemy(int x, int y);
//variables	
	Player player;
	std::vector<Block> blocks;
	std::vector<BoundingBox> boxes;
	std::vector<Enemy> enemies;
	UTexture tex;
	int amount = 1.5;
	sf::Image level;
	int size = 20;
};