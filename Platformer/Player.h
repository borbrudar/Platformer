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

	}
	void updatePlayer(Vector2f pos);
	void drawPlayer(RenderWindow &window);
	Animation ani;
	Sprite sprite;
	int size = 40;
	unsigned int id;
};