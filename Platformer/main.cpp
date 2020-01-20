#include <sfml/Graphics.hpp>

#include "World.h"

using namespace sf;
int main() {
	//setup
	RenderWindow window;
	window.create(VideoMode(800, 600), "Super Mario");
	Event e;

	World world;
	//game loop
	while (window.isOpen()) {
		int moved = 0;
		while (window.pollEvent(e)) {
			if (e.type == Event::Closed) window.close();
			if (Keyboard::isKeyPressed(Keyboard::Escape)) window.close();
			if (Keyboard::isKeyPressed(Keyboard::Left)) moved = 1;
			if (Keyboard::isKeyPressed(Keyboard::Right)) moved = 2;
		}

		world.updateWorld(moved);
		
		window.clear(Color(128,128,128));
		world.drawWorld(window);
		window.display();
	}

	return 0;
}