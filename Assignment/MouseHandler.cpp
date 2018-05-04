#include "MouseHandler.h"



MouseHandler::MouseHandler()
{
}


MouseHandler::~MouseHandler()
{
}

void MouseHandler::update(SDL_Event* event) {
	//check if user has clicked on Hero
	if (event->type == SDL_MOUSEBUTTONDOWN) {
		//check if its the left mouse button
		if (event->button.button == SDL_BUTTON_LEFT) {
			//check if its clicked on the hero region
			if (event->button.x >= hero->pos.x && event->button.x <= hero->pos.x + 36 && event->button.y >= hero->pos.y && event->button.y <= hero->pos.y + 36) {
				leftMousePressedDown = true;
			}
		}
	}
	//check if mouse button released
	if (event->type == SDL_MOUSEBUTTONUP) {
		if (event->button.button == SDL_BUTTON_LEFT)
			leftMousePressedDown = false;
	}
	//if left pressed and mouse moving, drag hero around
	if (leftMousePressedDown && event->type == SDL_MOUSEMOTION) {
		hero->pos.x = event->motion.x;
		hero->pos.y = event->motion.y;
	}

}

void MouseHandler::hoverMouse(SDL_Event * event, SDL_Renderer* renderer)
{
	int x, y;
	SDL_GetMouseState(&x, &y);
	if (x >= 175 && x <= 465 && y >= 185 && y <= 235)
		userInterface.highlightStory(renderer);
	if (x >= 175 && x <= 465 && y >= 255 && y <= 305)
		userInterface.highlightStartGame(renderer);
	if (x >= 175 && x <= 465 && y >= 325 && y <= 375)
		userInterface.highlightInstructions(renderer);
	if (x >= 175 && x <= 465 && y >= 395 && y <= 445)
		userInterface.highlightExitGame(renderer);
	
}

bool MouseHandler::clickStory(SDL_Event * event) { //click story function
	if (event->type == SDL_MOUSEBUTTONDOWN) {
		if (event->button.button == SDL_BUTTON_LEFT) {
			if (event->button.x >= 175 && event->button.x <= 465 && event->button.y >= 185 && event->button.y <= 235) {
				leftMousePressedDown = true;
			}
		}
	}
	if (event->type == SDL_MOUSEBUTTONUP) {
		if (event->button.button == SDL_BUTTON_LEFT)
			leftMousePressedDown = false;
	}

	return leftMousePressedDown;

}

bool MouseHandler::clickStartGame(SDL_Event * event) { //click start game function
	if (event->type == SDL_MOUSEBUTTONDOWN) {
		if (event->button.button == SDL_BUTTON_LEFT) {
			if (event->button.x >= 175 && event->button.x <= 465 && event->button.y >= 255 && event->button.y <= 305) {
				leftMousePressedDown = true;
			}
		}
	}
	if (event->type == SDL_MOUSEBUTTONUP) {
		if (event->button.button == SDL_BUTTON_LEFT)
			leftMousePressedDown = false;
	}

	return leftMousePressedDown;

}

bool MouseHandler::clickInstructions(SDL_Event * event) { //click story function
	if (event->type == SDL_MOUSEBUTTONDOWN) {
		if (event->button.button == SDL_BUTTON_LEFT) {
			if (event->button.x >= 175 && event->button.x <= 465 && event->button.y >= 325 && event->button.y <= 375) {
				leftMousePressedDown = true;
			}
		}
	}
	if (event->type == SDL_MOUSEBUTTONUP) {
		if (event->button.button == SDL_BUTTON_LEFT)
			leftMousePressedDown = false;
	}

	return leftMousePressedDown;

}

bool MouseHandler::clickExitGame(SDL_Event * event) { //click story function
	if (event->type == SDL_MOUSEBUTTONDOWN) {
		if (event->button.button == SDL_BUTTON_LEFT) {
			if (event->button.x >= 175 && event->button.x <= 465 && event->button.y >= 395 && event->button.y <= 445) {
				leftMousePressedDown = true;
			}
		}
	}
	if (event->type == SDL_MOUSEBUTTONUP) {
		if (event->button.button == SDL_BUTTON_LEFT)
			leftMousePressedDown = false;
	}

	return leftMousePressedDown;

}