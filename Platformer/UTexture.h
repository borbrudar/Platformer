#pragma once
#include <SFML/Graphics.hpp>

class UTexture {
public:
	UTexture() {
		texture.loadFromFile("textures/stone.jpg");
	}
	sf::Texture texture;
};