#pragma once
#include "Text.h"
#include "KeyboardHandler.h"

class UserInterface
{
	KeyboardHandler keyboardHandler;
	Text text;
public:
	UserInterface();
	~UserInterface();

	void menu(SDL_Renderer* renderer);
	void highlightStory(SDL_Renderer* renderer);
	void highlightStartGame(SDL_Renderer* renderer);	
	void highlightInstructions(SDL_Renderer* renderer);
	void highlightExitGame(SDL_Renderer* renderer);
	void storyPage1(SDL_Surface* surface, SDL_Texture* texture, SDL_Renderer* renderer, SDL_Window* window, SDL_Event* event);
	void storyPage2(SDL_Surface* surface, SDL_Texture* texture, SDL_Renderer* renderer, SDL_Window* window, SDL_Event* event);
	void storyPage3(SDL_Surface* surface, SDL_Texture* texture, SDL_Renderer* renderer, SDL_Window* window, SDL_Event* event);
	void storyPage4(SDL_Surface* surface, SDL_Texture* texture, SDL_Renderer* renderer, SDL_Window* window, SDL_Event* event);
	void storyPage5(SDL_Surface* surface, SDL_Texture* texture, SDL_Renderer* renderer, SDL_Window* window, SDL_Event* event);
};
