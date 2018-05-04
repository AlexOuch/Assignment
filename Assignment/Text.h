#pragma once
#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

using namespace std;

class Text
{
protected:
	TTF_Font * font;
	SDL_Color textColor;
	SDL_Surface* textSurface;
	SDL_Texture* textTexture;

	SDL_Rect textDestination;
	
public:


	Text();
	~Text();
	void pikachuEscape(SDL_Renderer* renderer); //menu title "PIKACHU ESCAPE"
	void startGame(bool highlight, SDL_Renderer* renderer); //menu button "START GAME"
	void instructions(bool highlight, SDL_Renderer* renderer); //menu button "INSTRUCTIONS"
	void exitGame(bool highlight, SDL_Renderer* renderer); //menu button "EXIT GAME"
	void story(bool highlight, SDL_Renderer* renderer); //menu button "STORY"

	void storyPage1(SDL_Renderer* renderer);
	void storyPage2(SDL_Renderer* renderer);
	void storyPage3(SDL_Renderer* renderer);
	void storyPage4(SDL_Renderer* renderer);
	void storyPage5(SDL_Renderer* renderer);
	void nextPageText(SDL_Renderer* renderer);

};

