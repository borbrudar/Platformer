#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
class Enemy {
public:
	void drawEnemy(RenderWindow &window);
	void loadEnemy(Texture &t);
	void setPosition(int x, int y);
	Sprite sprite;
};