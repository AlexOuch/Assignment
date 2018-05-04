#pragma once
#include "InputHandler.h"

class GameControllerHandler : public InputHandler
{
public:
	SDL_GameController * controller;

	GameControllerHandler();
	~GameControllerHandler();

	void update(SDL_Event * event);
};
