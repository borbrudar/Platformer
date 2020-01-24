#pragma once
#include <SFML/Graphics.hpp>
#include "BoundingBox.h"

using namespace sf;
class Enemy {
public:
	Enemy(int x, int y, int size);
	void updateEnemy(bool right, bool left, int amount);
	void drawEnemy(RenderWindow &window);
	void loadEnemy(Texture &t);
	void setPosition(int x, int y);
	BoundingBox box;
	Sprite sprite;
};