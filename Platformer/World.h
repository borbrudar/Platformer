#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
class World {
public:
	World() {
		ground.setFillColor(Color::Green);
		ground.setSize(Vector2f(800, 30));
		ground.setPosition(0, 570);
	}
	void drawWorld(RenderWindow &window);
	RectangleShape ground;
};