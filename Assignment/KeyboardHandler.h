#pragma once
#include "InputHandler.h"

class KeyboardHandler : public InputHandler
{
public:
	KeyboardHandler();
	~KeyboardHandler();

	void update(SDL_Event* event);
	bool nextPage(SDL_Event* event);
};

