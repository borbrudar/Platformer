#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include <vector>

using namespace sf;

enum class type {
	block,
	enemy,
	item,
	player
};

class BoundingBox {
public:
	BoundingBox() = default;
	BoundingBox(int x, int y, int size);
	void updateBox(int amount);
	void updateBox(int amount, std::vector<BoundingBox> boxes);
	int updateBox(std::vector<BoundingBox> boxes, Sprite &s, Animation &ani);
	void setBox(int width, int height);
	void setPosition(int x, int y);
	int checkCollision(BoundingBox box);

	Vector2f pos;
	int width, height;
	type type = type::enemy;
	float vel = 0, acc = .03f, jumpVel = 3.1f;
	bool touchingGround = 0;
	bool jumped = 0;
	unsigned int id;
};