#include<iostream>
#include "Timer.h"
#include "SpaceDelay.h"
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


#pragma region Create  background, Characters, Timer and global time
	// create background
	Background bg;

	// character 1
	Character* ch1 = new CharacterWASD(Vector2f(200, 300));
	// character 2
	Character* ch2 = new CharacterArrows(Vector2f(900 - 200, 900 - 300));

	// create hand(Space delay)
	// needed to print hand.png and inform player about Space delay
	SpaceDelay* sd = new SpaceDelay();
	sd->setCurrentTime(0);

	// timer
	Timer timer;
	timer.setTimeStop(15);

	// global time
	Clock clock;
	Time time;
	float globaTime = 0;
	float frameTime = 0;
#pragma endregion


	// TODO delete hand delay and create the class hand delay
	// TODO: Maybe animation
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

#pragma region Set time / check time end 
		if (timer.checkTimeStop()) { win.close(); }

		frameTime = clock.getElapsedTime().asSeconds();
		globaTime += frameTime;
		timer.setTime(globaTime);

		clock.restart();
#pragma endregion

		// touch
		if (sd->checkTimeTrue(globaTime)) {
			if (Keyboard::isKeyPressed(Keyboard::Space)) { 
				sd->setCurrentTime(globaTime);
				if (ch2->getCharacter().getGlobalBounds().intersects(ch1->getCharacter().getGlobalBounds())) { win.close(); }		
				sd->halfTransparent();
			}
		}
	


#pragma region Draw
		// draw Characters
		win.draw(ch1->getCharacter());
		win.draw(ch2->getCharacter());

		// draw time
		win.draw(timer.getText());

		// draw Space delay
		win.draw(sd->getCharacter());
		win.draw(sd->getText());
#pragma endregion

		
		win.display();
	}
}