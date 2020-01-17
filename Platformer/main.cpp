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
		while (window.pollEvent(e)) {
			if (e.type == Event::Closed) window.close();
		}

		window.clear(Color(128,128,128));
		world.drawWorld(window);
		window.display();
	}

	return 0;
}