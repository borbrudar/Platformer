#pragma once
#include <SFML/Graphics.hpp>

enum class entity_type {
	block,
	enemy,
	item,
	player
};

enum class block_type {
	stone,
	dirt
};

using namespace sf;
class Entity {
public:
	Entity(entity_type type) : type(type) {};
	void loadEntity(Texture &t, float x = 1, float y = 1);
	void updateEntity(Vector2f pos);
	void drawEntity(RenderWindow &window);
	entity_type type = entity_type::block;
	block_type blockType = block_type::stone;
	Sprite sprite;
	unsigned int id;
};