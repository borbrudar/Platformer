#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "BoundingBox.h"
#include "UTexture.h"

#include <string>
#include <vector>


using namespace sf;
class Player {
public:
	Player() {
		std::vector<std::string> string;
		string.push_back("textures/sprite1.png");
		string.push_back("textures/sprite2.png");
		string.push_back("textures/sprite3.png");
		ani.loadAnimaton(string);

		sprite.setTexture(ani.textures[0]);
		sprite.setScale(2,2);

		box.setBox(size, size);
	}
	int updatePlayer(std::vector<BoundingBox> boxes, bool jumped);
	void drawPlayer(RenderWindow &window);
	Animation ani;
	Sprite sprite;
	int size = 40;
	BoundingBox box;
	bool touchingGround = 0;
	float vel = 0, acc = .03f, jumpVel = 3.1f;
	unsigned int id;
};