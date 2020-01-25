#pragma once
#include <SFML/Graphics.hpp>
#include "BoundingBox.h"

enum class block_type {
	stone,
	dirt
};

using namespace sf;
class Block {
public:
	void updateBlock(Vector2f pos);
	void loadBlock(Texture &t);
	void setPosition(int x, int y);
	void drawBlock(RenderWindow &window);
	Sprite sprite;
	block_type type = block_type::stone;
	unsigned int id;
};