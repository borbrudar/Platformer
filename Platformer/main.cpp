#include <sfml/Graphics.hpp>

#include "World.h"

using namespace sf;
int main() {
	//setup
	RenderWindow window;
	window.create(VideoMode(800, 600), "Super Mario");
	Event e;

	World world;
	bool right = 0, left = 0, up = 0;
	//game loop
	while (window.isOpen()) {
		
		while (window.pollEvent(e)) {
			if (e.type == Event::Closed) window.close();
			if (Keyboard::isKeyPressed(Keyboard::Escape)) window.close();

			if (e.type == Event::KeyPressed) {
				if (e.key.code == Keyboard::Left) right = 1;
				if (e.key.code == Keyboard::Right) left = 1;
				if ((e.key.code == Keyboard::Space) || (e.key.code == Keyboard::Up)) up = 1;
			}
			if (e.type == Event::KeyReleased) {
				if (e.key.code == Keyboard::Left)  right = 0;
				if (e.key.code == Keyboard::Right) left = 0;
				if ((e.key.code == Keyboard::Space) || (e.key.code == Keyboard::Up)) up = 0;
			}
		}

		world.updateWorld(right, left, up);
		
		window.clear(Color(128,128,128));
		world.drawWorld(window);
		window.display();
	}

	return 0;
}