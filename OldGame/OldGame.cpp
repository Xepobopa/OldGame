#include<iostream>
#include "Timer.h"
#include "Background.h"
#include "CharacterWASD.h"
#include "CharacterArrows.h"
#include<SFML/Graphics.hpp>
#define WINDOW_WIDTH 900
#define WINDOW_HEIGHT 900

using namespace sf;

int main()
{
	RenderWindow win(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Old Good Games");
	// v-sync
	win.setVerticalSyncEnabled(true);

	// total time
	Clock clock;
	Time time;
	float frametime = 0;

	// create background
	Background bg;

	// character 1
	Character* ch1 = new CharacterWASD(Vector2f(200, 300));
	// character 2
	Character* ch2 = new CharacterArrows(Vector2f(900 - 200, 900 - 300));

	// timer
	Timer timer;


	while (win.isOpen())
	{
		Event event;
		while (win.pollEvent(event))
		{
			if (event.type == Event::Closed) { win.close(); }
		}

		
		// draw bg
		win.draw(bg.getBackground());
		
	#pragma region CharacterWASD Movement
		if (Keyboard::isKeyPressed(Keyboard::D)) { ch1->moveRight(); }
		if (Keyboard::isKeyPressed(Keyboard::A)) { ch1->moveLeft(); }
		if (Keyboard::isKeyPressed(Keyboard::W)) { ch1->moveTop(); }
		if (Keyboard::isKeyPressed(Keyboard::S)) { ch1->moveBottom(); }
	#pragma endregion
	#pragma region CharacterArrows Movement
		if (Keyboard::isKeyPressed(Keyboard::Right)) { ch2->moveRight(); }
		if (Keyboard::isKeyPressed(Keyboard::Left)) { ch2->moveLeft(); }
		if (Keyboard::isKeyPressed(Keyboard::Up)) { ch2->moveTop(); }
		if (Keyboard::isKeyPressed(Keyboard::Down)) { ch2->moveBottom(); }
	#pragma endregion

		// time end 
		std::cout << timer.getTime() << std::endl;
		if (timer.getTime() >= 10) { win.close(); }

		// touch
		if (ch2->getCharacter().getGlobalBounds().intersects(ch1->getCharacter().getGlobalBounds())) { win.close(); }

		// draw Characters
		win.draw(ch1->getCharacter());
		win.draw(ch2->getCharacter());

		
		win.display();
	}
}