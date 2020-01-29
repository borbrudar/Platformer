#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
class Item {
public:
	void updateItem(Vector2f pos);
	void drawItem(RenderWindow &window);
	void loadItem(Texture &t);
	void setPosition(int x, int y);
	Sprite sprite;
	unsigned int id;
};