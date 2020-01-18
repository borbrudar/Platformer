#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
class Block {
public:
	Block() {
		shape.setSize(Vector2f(20, 20));
	}
	void updateBlock(bool moved, bool right, int amount);
	void loadBlock(Texture &t);
	void setPosition(int x, int y);
	void drawBlock(RenderWindow &window);
	RectangleShape shape;
	Sprite sprite;
};