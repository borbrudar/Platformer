#pragma once
#include <SFML/Graphics.hpp>

enum class entity_type {
	block,
	enemy,
	item,
	player
};

using namespace sf;
class Entity {
public:
	Entity(entity_type type) : type(type) {};
	void loadEntity(Texture &t, int x = 0, int y = 0);
	void updateEntity(Vector2f pos);
	void drawEntity(RenderWindow &window);
	entity_type type = entity_type::block;
	Sprite sprite;
	unsigned int id;
};