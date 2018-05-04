#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <list>
#include "Animation.h"
#include "Entity.h"
#include "Hero.h"
#include "InputHandler.h"
#include "KeyboardHandler.h"
#include "MouseHandler.h"
#include "GameControllerHandler.h"
#include "Text.h"
#include "UserInterface.h"

using namespace std;

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
SDL_Surface* surface = NULL;

SDL_Texture* texture;
SDL_Rect sourceRectangle;
SDL_Rect destinationRectangle;


int main(int argc, char **argv) {

	//initialising SDL with everything
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		cout << "SDL failed to initialise" << endl;
		return -1;
	}
	else
		cout << "SDL initialised success" << endl;

	//initialising png image
	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
		cout << "sdl image did not load: " << IMG_GetError() << endl;
		SDL_Quit();
		system("pause");
		return -1;
	}

	//create window
	window = SDL_CreateWindow("Pikachu game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);

	if (window != NULL)
		cout << "Window created" << endl;
	else {
		cout << "Failed to create window" << endl;
		return -1;
	}

	//create renderer
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer != NULL)
		cout << "Renderer created" << endl;
	else {
		cout << "Failed to create renderer" << endl;
		return -1;
	}

	//initialise sdl ttf for text
	if (TTF_Init() != 0) {
		cout << "sdl ttf failed" << endl;
		system("pause");
		SDL_Quit();
		return -1;
	}

	//Get controller mappings
	SDL_GameControllerAddMappingsFromFile("assets/gamecontrollerdb.txt");

	//initiate png image
	SDL_Texture* pikachuSpriteSheet = IMG_LoadTexture(renderer, "assets/pikachu.png");
	SDL_Rect pikachuClipRect = { 0, 0, 36, 36 };
	SDL_Rect pikachuDestRect = { 0, 0, 144, 36 };
	SDL_Surface* pikachuSurface = IMG_Load("assets/pikachu.png");

	SDL_SetColorKey(pikachuSurface, 1, SDL_MapRGB(pikachuSurface->format, 255, 255, 255));
	SDL_Texture* pikachuSpriteSheetTransparent = SDL_CreateTextureFromSurface(renderer, pikachuSurface);
	SDL_FreeSurface(pikachuSurface);

	//Animation objects
	Animation pikachuAnim(pikachuSpriteSheetTransparent, renderer, 4, 36, 36, 0.1);

	//setup time stuff
	Uint32 lastUpdate = SDL_GetTicks();

	//list of game entities
	list<Entity*>entities;
	Hero* pikachu = new Hero();
	pikachu->setAnimation(&pikachuAnim);
	pikachu->setRenderer(renderer);

	//vector for starting position
	Vector pikachuStartPos(0, 0);
	pikachu->setPosition(pikachuStartPos);
	
	//input handlers
	KeyboardHandler keyboardHandler;
	keyboardHandler.hero = pikachu;

	MouseHandler mouseHandler;
	mouseHandler.hero = pikachu;

	GameControllerHandler controllerHandler;
	controllerHandler.hero = pikachu;

	//add out hero to the list
	entities.push_back(pikachu);

	UserInterface userInterface;

	Text text;

	//game loop
	bool loop = true;
	while (loop) {
		//time stuff
		Uint32 timeDiff = SDL_GetTicks() - lastUpdate;
		float DT = timeDiff / 1000.0;
		lastUpdate = SDL_GetTicks();
		
		userInterface.menu(renderer);
		
		SDL_Event e;		
		while (SDL_PollEvent(&e)) {			
			mouseHandler.hoverMouse(&e, renderer);
			bool clickStory = mouseHandler.clickStory(&e);
			bool clickStartGame = mouseHandler.clickStartGame(&e);
			bool clickInstructions = mouseHandler.clickInstructions(&e);
			bool clickExitGame = mouseHandler.clickExitGame(&e);

			if (clickStory) {
				while (clickStory) {

					userInterface.storyPage1(surface, texture, renderer, window, &e);
					system("pause");
					userInterface.storyPage2(surface, texture, renderer, window, &e);
					system("pause");
					userInterface.storyPage3(surface, texture, renderer, window, &e);
					system("pause");
					userInterface.storyPage4(surface, texture, renderer, window, &e);
					system("pause");
					userInterface.storyPage5(surface, texture, renderer, window, &e);
					system("pause");

					clickStory = false;

				}
			}
			else if (clickStartGame) {
				while (clickStartGame) {

					
					SDL_Event f;

					while (SDL_PollEvent(&f)) {
						//check if user has clicked on the close window button
						if (f.type == SDL_QUIT)
							loop = false;

						if (f.type == SDL_KEYDOWN) { //check if user pressed a button
							if (f.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
								clickStartGame = false;
						}

						if (controllerHandler.controller != NULL)
							controllerHandler.update(&f);
						else
							keyboardHandler.update(&f);

						mouseHandler.update(&f);

					}


					for (list<Entity*>::iterator eIt = entities.begin(); eIt != entities.end(); eIt++) {
						(*eIt)->update(DT);
						(*eIt)->draw();
					}

					SDL_RenderPresent(renderer);
					SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
					SDL_RenderClear(renderer);

				}
			}
			else if (clickInstructions) {
				while (clickStartGame) {
					cout << "instructions";
				}
			}
			else if (clickExitGame) {
				loop = false;
			}


		}


		
		//animation stuff

		
		/*
		//User input stuff
		SDL_Event f;

		while (SDL_PollEvent(&e)) {
			//check if user has clicked on the close window button
			if (e.type == SDL_QUIT)
				loop = false;

			if (e.type == SDL_KEYDOWN) { //check if user pressed a button
				if (e.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
					loop = false;
			}

			if (controllerHandler.controller != NULL)
				controllerHandler.update(&e);
			else
				keyboardHandler.update(&e);

			mouseHandler.update(&e);

		}
		
		
		for (list<Entity*>::iterator eIt = entities.begin(); eIt != entities.end(); eIt++) {
			(*eIt)->update(DT);
			(*eIt)->draw();
		}
		*/
	
		
		SDL_RenderPresent(renderer);

	}

	delete pikachu;
	
	SDL_DestroyTexture(pikachuSpriteSheet);
	SDL_DestroyTexture(pikachuSpriteSheetTransparent);

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	system("pause");
	return 0;
}