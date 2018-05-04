#pragma once
#include "InputHandler.h"
#include "UserInterface.h"
class MouseHandler : public InputHandler
{
	UserInterface userInterface;
public:
	bool leftMousePressedDown = false;
	bool hover = false;

	MouseHandler();
	~MouseHandler();

	void update(SDL_Event* event);
	void hoverMouse(SDL_Event* event, SDL_Renderer* renderer); //event for when user hovers over any of the options
	bool clickStory(SDL_Event* event); //event for when user clicks on story
	bool clickStartGame(SDL_Event* event); //event for when user clicks on Start Game
	bool clickInstructions(SDL_Event* event); //event for when user clicks on Instructions
	bool clickExitGame(SDL_Event* event); //event for when user clicks on Exit Game
};

