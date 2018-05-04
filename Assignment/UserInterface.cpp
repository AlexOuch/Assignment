#include "UserInterface.h"



UserInterface::UserInterface()
{
}


UserInterface::~UserInterface()
{
}

void UserInterface::menu(SDL_Renderer * renderer)
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); //black
	SDL_RenderClear(renderer); //clear screen with black

	SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
	SDL_Rect rect = { 170, 180, 300, 50 };
	SDL_Rect rect1 = { 170, 250, 300, 50 };
	SDL_Rect rect2 = { 170, 320, 300, 50 };
	SDL_Rect rect3 = { 170, 390, 300, 50 };
	SDL_RenderFillRect(renderer, &rect);
	SDL_RenderFillRect(renderer, &rect1);
	SDL_RenderFillRect(renderer, &rect2);
	SDL_RenderFillRect(renderer, &rect3);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_Rect rect4 = { 175, 185, 290, 40 };
	SDL_Rect rect5 = { 175, 255, 290, 40 };
	SDL_Rect rect6 = { 175, 325, 290, 40 };
	SDL_Rect rect7 = { 175, 395, 290, 40 };
	SDL_RenderFillRect(renderer, &rect4);
	SDL_RenderFillRect(renderer, &rect5);
	SDL_RenderFillRect(renderer, &rect6);
	SDL_RenderFillRect(renderer, &rect7);

	text.pikachuEscape(renderer);
	text.story(false, renderer);
	text.startGame(false, renderer);
	text.instructions(false, renderer);
	text.exitGame(false, renderer);
	
}

void UserInterface::highlightStory(SDL_Renderer * renderer) {
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 225);
	SDL_Rect rect4 = { 175, 185, 290, 40 };
	SDL_RenderFillRect(renderer, &rect4);
	text.story(true, renderer);
}

void UserInterface::highlightStartGame(SDL_Renderer * renderer) {
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 225);
	SDL_Rect rect5 = { 175, 255, 290, 40 };
	SDL_RenderFillRect(renderer, &rect5);
	text.startGame(true, renderer);
}

void UserInterface::highlightInstructions(SDL_Renderer * renderer) {
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 225);
	SDL_Rect rect6 = { 175, 325, 290, 40 };
	SDL_RenderFillRect(renderer, &rect6);
	text.instructions(true, renderer);
}

void UserInterface::highlightExitGame(SDL_Renderer * renderer) {
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 225);
	SDL_Rect rect7 = { 175, 395, 290, 40 };
	SDL_RenderFillRect(renderer, &rect7);
	text.exitGame(true, renderer);
}

void UserInterface::storyPage1(SDL_Surface * surface, SDL_Texture * texture, SDL_Renderer* renderer, SDL_Window* window, SDL_Event* event)
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); //black
	SDL_RenderClear(renderer); //clear screen with black
	surface = IMG_Load("assets/pikachu2.png");

	texture = SDL_CreateTextureFromSurface(renderer, surface);


	SDL_Rect image1;
	image1.x = 0;
	image1.y = 0;
	SDL_Rect destImage1;
	destImage1.x = 200;
	destImage1.y = 270;

	SDL_QueryTexture(texture, NULL, NULL, &image1.w, &image1.h);

	destImage1.w = image1.w;
	destImage1.h = image1.h;
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, &image1, &destImage1);

	text.storyPage1(renderer);
	SDL_RenderPresent(renderer);

	SDL_RenderClear(renderer);
}

void UserInterface::storyPage2(SDL_Surface* surface, SDL_Texture* texture, SDL_Renderer* renderer, SDL_Window* window, SDL_Event* event) {
	

	SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255 );
	SDL_RenderClear(renderer);

	// image 2
	surface = IMG_Load("assets/team.png");

	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_Rect image2;
	image2.x = 0;
	image2.y = 0;
	SDL_Rect destImage2;
	destImage2.x = 200;
	destImage2.y = 270;

	SDL_QueryTexture(texture, NULL, NULL, &image2.w, &image2.h);

	destImage2.w = image2.w;
	destImage2.h = image2.h;
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, &image2, &destImage2);

	text.storyPage2(renderer);
	SDL_RenderPresent(renderer);
	SDL_RenderClear(renderer);

}
	


void UserInterface::storyPage3(SDL_Surface* surface, SDL_Texture* texture, SDL_Renderer* renderer, SDL_Window* window, SDL_Event* event) {


	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	// image 3

	surface = IMG_Load("assets/final.png");

	texture = SDL_CreateTextureFromSurface(renderer, surface);


	SDL_Rect image3;
	image3.x = 0;
	image3.y = 0;
	SDL_Rect destImage3;
	destImage3.x = 100;
	destImage3.y = 200;

	SDL_QueryTexture(texture, NULL, NULL, &image3.w, &image3.h);

	destImage3.w = image3.w;
	destImage3.h = image3.h;
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, &image3, &destImage3);

	text.storyPage3(renderer);
	SDL_RenderPresent(renderer);
	SDL_RenderClear(renderer);


}

void UserInterface::storyPage4(SDL_Surface* surface, SDL_Texture* texture, SDL_Renderer* renderer, SDL_Window* window, SDL_Event* event) {

	

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	// image 4
	surface = IMG_Load("assets/pop.png");

	texture = SDL_CreateTextureFromSurface(renderer, surface);


	SDL_Rect image4;
	image4.x = 0;
	image4.y = 0;
	SDL_Rect destImage4;
	destImage4.x = 200;
	destImage4.y = 270;

	SDL_QueryTexture(texture, NULL, NULL, &image4.w, &image4.h);

	destImage4.w = image4.w;
	destImage4.h = image4.h;
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, &image4, &destImage4);

	text.storyPage4(renderer);
	SDL_RenderPresent(renderer);
	SDL_RenderClear(renderer);

}

void UserInterface::storyPage5(SDL_Surface* surface, SDL_Texture* texture, SDL_Renderer* renderer, SDL_Window* window, SDL_Event* event) {

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	// image 5
	
	surface = IMG_Load("assets/caught.png");

	texture = SDL_CreateTextureFromSurface(renderer, surface);

	SDL_Rect image5;
	image5.x = 0;
	image5.y = 0;
	SDL_Rect destImage5;
	destImage5.x = 200;
	destImage5.y = 270;

	SDL_QueryTexture(texture, NULL, NULL, &image5.w, &image5.h);

	destImage5.w = image5.w;
	destImage5.h = image5.h;
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, &image5, &destImage5);

	text.storyPage5(renderer);
	SDL_RenderPresent(renderer);
}
/*
SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
SDL_Rect rect8 = { 0, 0, 640, 480 };
SDL_RenderFillRect(renderer, &rect8);
SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
SDL_Rect rect9 = { 5, 5, 630, 470 };
SDL_RenderFillRect(renderer, &rect9);
commit test number 3
*/
