#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class UTexture {
public:
	UTexture() {
		texture.resize(4);
		texture[0].loadFromFile("textures/stone.png");
		texture[1].loadFromFile("textures/dirt.png");
		texture[2].loadFromFile("textures/enemy.png");
		texture[3].loadFromFile("textures/item1.png");
	}
	std::vector<sf::Texture> texture;
};