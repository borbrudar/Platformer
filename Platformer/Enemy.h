#pragma once
#include <SFML/Graphics.hpp>
#include "BoundingBox.h"

using namespace sf;
class Enemy {
public:
	void updateEnemy(Vector2f pos);
	void drawEnemy(RenderWindow &window);
	void loadEnemy(Texture &t);
	void setPosition(int x, int y);
	Sprite sprite;
	unsigned int id;
};