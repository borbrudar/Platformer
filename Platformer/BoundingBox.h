#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

using namespace sf;

enum class type {
	block,
	enemy,
	player
};

class BoundingBox {
public:
	BoundingBox() = default;
	BoundingBox(int x, int y, int size);
	void updateBox(int amount);
	void updateBox(int amount, std::vector<BoundingBox> boxes);
	void setBox(int width, int height);
	void setPosition(int x, int y);
	int checkCollision(BoundingBox box);

	Vector2f pos;
	int width, height;
	type type = type::enemy;
	float acc = 0.1f, vel = 0;
	bool touchingGround = 0;
	unsigned int id;
};