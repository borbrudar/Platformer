#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

using namespace sf;
class Animation {
public:
	void loadAnimaton(std::vector<std::string> string) {
		textures.resize(string.size());
		texNum = string.size();

		for (int i = 0; i < texNum; i++) {
			textures[i].loadFromFile(string[i]);
			
		}
	}
	std::vector<Texture> textures;
	int texNum;
};