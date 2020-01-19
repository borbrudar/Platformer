#include <sfml/Graphics.hpp>

#include "World.h"

using namespace sf;
int main() {
	//setup
	RenderWindow window;
	window.create(VideoMode(800, 600), "Super Mario");
	Event e;

	World world;
	bool moved = 0, right = 0;
	//game loop
	while (window.isOpen()) {
		while (window.pollEvent(e)) {
			if (e.type == Event::Closed) window.close();
			if (Keyboard::isKeyPressed(Keyboard::Escape)) window.close();

			moved = 0;
			if (Keyboard::isKeyPressed(Keyboard::Left)) {
				moved = 1; right = 0;
			}
			else if (Keyboard::isKeyPressed(Keyboard::Right)) {
				moved = 1; right = 1;
			}
		}

		world.updateWorld(moved, right);
		
		window.clear(Color(128,128,128));
		world.drawWorld(window);
		window.display();
	}

	return 0;
}