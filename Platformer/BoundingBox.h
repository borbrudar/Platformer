#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
class BoundingBox {
public:
	void updateBox(bool right, bool left, int amount);
	void setBox(int width, int height);
	void setPosition(int x, int y);
	bool checkCollision(BoundingBox box);
	Vector2f pos;
	int width, height;
};