#pragma once
#include <SFML/Graphics.hpp>
#include "BoundingBox.h"

enum class type {
	stone,
	dirt
};

using namespace sf;
class Block {
public:
	Block(int x, int y, int size);
	void updateBlock(bool right, bool left, int amount);
	void loadBlock(Texture &t);
	void setPosition(int x, int y);
	void drawBlock(RenderWindow &window);
	BoundingBox box;
	Sprite sprite;
	type type = type::stone;
};