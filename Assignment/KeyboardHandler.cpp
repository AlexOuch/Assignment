#include "KeyboardHandler.h"



KeyboardHandler::KeyboardHandler()
{
}


KeyboardHandler::~KeyboardHandler()
{
}

void KeyboardHandler::update(SDL_Event * event) {
	//button presses for out hero
	if (event->type == SDL_KEYDOWN) {
		//reset hero position if press R
		if (event->key.keysym.scancode == SDL_SCANCODE_R) {
			hero->pos.x = 200;
			hero->pos.y = 200;
		}
		//TODO add attacks or other actions here for button presses

	}

	//check if a button is held down
	//first get state of all keyboard buttons (1 pressed, 0 not pressed)
	const Uint8 *keystates = SDL_GetKeyboardState(NULL); //you can pass it a smaller array, or null to return all keys
														 //if holding up key
	if (keystates[SDL_SCANCODE_UP])
		hero->velocity.y = -500;
	if (keystates[SDL_SCANCODE_DOWN])
		hero->velocity.y = 500;
	if (keystates[SDL_SCANCODE_LEFT])
		hero->velocity.x = -500;
	if (keystates[SDL_SCANCODE_RIGHT])
		hero->velocity.x = 500;
	//check if none are held down
	if (!keystates[SDL_SCANCODE_UP] && !keystates[SDL_SCANCODE_DOWN]) {
		hero->velocity.y = 0;
	}
	if (!keystates[SDL_SCANCODE_LEFT] && !keystates[SDL_SCANCODE_RIGHT]) {
		hero->velocity.x = 0;
	}

}

bool KeyboardHandler::nextPage(SDL_Event * event)
{
	if (event->type == SDL_KEYDOWN) {
		if (event->key.keysym.scancode == SDL_SCANCODE_SPACE) {
			return true;
		}
		else
			return false;
	}
	else
		return false;
}
