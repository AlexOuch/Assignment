#include "Text.h"



Text::Text()
{

}


Text::~Text()
{
}

void Text::pikachuEscape(SDL_Renderer* renderer)
{
	font = TTF_OpenFont("assets/vermin_vibes_1989.ttf", 64);

	textColor = { 255, 255, 0, 255 };

	textSurface = TTF_RenderText_Blended(font, "PIKACHU ESCAPE", textColor);
	textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
	SDL_FreeSurface(textSurface);

	textDestination.x = 100;
	textDestination.y = 100;

	SDL_QueryTexture(textTexture, NULL, NULL, &textDestination.w, &textDestination.h);
	SDL_RenderCopy(renderer, textTexture, NULL, &textDestination);

}

void Text::startGame(bool highlight, SDL_Renderer* renderer)
{
	font = TTF_OpenFont("assets/vermin_vibes_1989.ttf", 32);

	if (highlight)
		textColor = { 0, 0, 0, 255 };
	else
		textColor = { 255, 255, 255, 255 };

	textSurface = TTF_RenderText_Blended(font, "START GAME", textColor);
	textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
	SDL_FreeSurface(textSurface);

	textDestination.x = 240;
	textDestination.y = 262;

	SDL_QueryTexture(textTexture, NULL, NULL, &textDestination.w, &textDestination.h);
	SDL_RenderCopy(renderer, textTexture, NULL, &textDestination);

}

void Text::instructions(bool highlight, SDL_Renderer* renderer)
{
	font = TTF_OpenFont("assets/vermin_vibes_1989.ttf", 32);

	if (highlight)
		textColor = { 0, 0, 0, 255 };
	else
		textColor = { 255, 255, 255, 255 };

	textSurface = TTF_RenderText_Blended(font, "INSTRUCTIONS", textColor);
	textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
	SDL_FreeSurface(textSurface);

	textDestination.x = 227;
	textDestination.y = 333;

	SDL_QueryTexture(textTexture, NULL, NULL, &textDestination.w, &textDestination.h);
	SDL_RenderCopy(renderer, textTexture, NULL, &textDestination);

}

void Text::exitGame(bool highlight, SDL_Renderer* renderer)
{
	font = TTF_OpenFont("assets/vermin_vibes_1989.ttf", 32);

	if (highlight)
		textColor = { 0, 0, 0, 255 };
	else
		textColor = { 255, 255, 255, 255 };

	textSurface = TTF_RenderText_Blended(font, "EXIT GAME", textColor);
	textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
	SDL_FreeSurface(textSurface);

	textDestination.x = 250;
	textDestination.y = 402;

	SDL_QueryTexture(textTexture, NULL, NULL, &textDestination.w, &textDestination.h);
	SDL_RenderCopy(renderer, textTexture, NULL, &textDestination);

}

void Text::story(bool highlight, SDL_Renderer* renderer)
{
	font = TTF_OpenFont("assets/vermin_vibes_1989.ttf", 32);

	if (highlight)
		textColor = { 0, 0, 0, 255 };
	else
		textColor = { 255, 255, 255, 255 };

	textSurface = TTF_RenderText_Blended(font, "STORY", textColor);
	textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
	SDL_FreeSurface(textSurface);

	textDestination.x = 272;
	textDestination.y = 194;

	SDL_QueryTexture(textTexture, NULL, NULL, &textDestination.w, &textDestination.h);
	SDL_RenderCopy(renderer, textTexture, NULL, &textDestination);

}

void Text::storyPage1(SDL_Renderer* renderer) //text in page 1 of story
{
	font = TTF_OpenFont("assets/vermin_vibes_1989.ttf", 32);
	
	textColor = { 255, 255, 255, 255 };

	textSurface = TTF_RenderText_Blended(font, "Once  upon  a  time  there  was  a  pikachu", textColor);
	textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
	SDL_FreeSurface(textSurface);

	textDestination.x = 15;
	textDestination.y = 50;

	SDL_QueryTexture(textTexture, NULL, NULL, &textDestination.w, &textDestination.h);
	SDL_RenderCopy(renderer, textTexture, NULL, &textDestination);

}

void Text::storyPage2(SDL_Renderer * renderer) //text in page 2 of story
{
	font = TTF_OpenFont("assets/vermin_vibes_1989.ttf", 32);

	textColor = { 255, 255, 255, 255 };

	textSurface = TTF_RenderText_Blended_Wrapped(font, "There  was  also  an  evil  gang  called Team Rocket", textColor, 600);
	textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
	SDL_FreeSurface(textSurface);

	textDestination.x = 15;
	textDestination.y = 50;

	SDL_QueryTexture(textTexture, NULL, NULL, &textDestination.w, &textDestination.h);
	SDL_RenderCopy(renderer, textTexture, NULL, &textDestination);
}

void Text::storyPage3(SDL_Renderer * renderer) //text in page 3 of story
{
	font = TTF_OpenFont("assets/vermin_vibes_1989.ttf", 32);

	textColor = { 255, 255, 255, 255 };

	textSurface = TTF_RenderText_Blended_Wrapped(font, "Team rocket has been trying to catch pikachu for the last 20 years", textColor, 600);
	textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
	SDL_FreeSurface(textSurface);

	textDestination.x = 15;
	textDestination.y = 50;

	SDL_QueryTexture(textTexture, NULL, NULL, &textDestination.w, &textDestination.h);
	SDL_RenderCopy(renderer, textTexture, NULL, &textDestination);
}

void Text::storyPage4(SDL_Renderer * renderer) //text in page 4 of story
{
	font = TTF_OpenFont("assets/vermin_vibes_1989.ttf", 32);

	textColor = { 255, 255, 255, 255 };

	textSurface = TTF_RenderText_Blended_Wrapped(font, "Today, they have finally succeeded", textColor, 600);
	textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
	SDL_FreeSurface(textSurface);

	textDestination.x = 15;
	textDestination.y = 50;

	SDL_QueryTexture(textTexture, NULL, NULL, &textDestination.w, &textDestination.h);
	SDL_RenderCopy(renderer, textTexture, NULL, &textDestination);
}

void Text::storyPage5(SDL_Renderer * renderer) //text in page 5 of story
{
	font = TTF_OpenFont("assets/vermin_vibes_1989.ttf", 32);

	textColor = { 255, 255, 255, 255 };

	textSurface = TTF_RenderText_Blended_Wrapped(font, "Your job is to play as pikachu and escape from team rocket", textColor, 600);
	textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
	SDL_FreeSurface(textSurface);

	textDestination.x = 15;
	textDestination.y = 50;

	SDL_QueryTexture(textTexture, NULL, NULL, &textDestination.w, &textDestination.h);
	SDL_RenderCopy(renderer, textTexture, NULL, &textDestination);
}

