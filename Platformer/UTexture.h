#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class UTexture {
public:
	UTexture() {
		texture.resize(2);
		texture[0].loadFromFile("textures/stone.png");
		texture[1].loadFromFile("textures/dirt.png");
	}
	std::vector<sf::Texture> texture;
};