#pragma once
#include <SFML/Graphics.hpp>
#include "BoundingBox.h"

using namespace sf;
class Player {
public:
	Player() {
		shape.setSize(Vector2f(size, size));
		shape.setFillColor(Color(0, 0, 255));

		box.setPosition(60, 500);
		box.setBox(size, size);
	}
	int updatePlayer(std::vector<BoundingBox> boxes, bool jumped);
	void drawPlayer(RenderWindow &window);
	RectangleShape shape;
	int size = 20;
	BoundingBox box;
	bool touchingGround = 0;
	float vel = 0, acc = .03f, jumpVel = 2.5f;
};