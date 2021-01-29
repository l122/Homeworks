#include<iostream>
#include <SDL2/SDL.h>
#include <stdio.h>


//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Function declarations
//Starts up SDL and creates window
bool init();
//Loads media
bool loadMedia();
//Frees media and shuts down SDL
void close();

//Global variables
//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//The image we will load and show on the screen
SDL_Surface* gHelloWorld = NULL;

int main (int argc, char * args[])
{
	//Start up SDL and create window
	if(!init())
	{
		std::cout << "Failed to initialize!" << std::endl;
	}
	else
	{
		//Load media
		if(!loadMedia())
		{
			std::cout << "Failed to load media!" << std::endl;
		}
		else
		{
			//Apply the image
			SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);
		}
	}

	//Update the surface
	SDL_UpdateWindowSurface(gWindow);

	//Wait two seconds
	SDL_Delay(2000);

	//Free resourcess and close SDL
	close();

	std::cout << "We are in function main" << std::endl;

	return EXIT_SUCCESS;
}

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "SDL could not initiaize! SDL_Error: " << SDL_GetError();
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, 
													SDL_WINDOWPOS_UNDEFINED, 
													SCREEN_WIDTH, SCREEN_HEIGHT, 
													SDL_WINDOW_SHOWN);
		if(gWindow == NULL)
		{
			std::cout << "Window could not be created! SDL_Error: " << SDL_GetError();
			success = false;
		}
		else 
		{
			//Get window surface
			gScreenSurface = SDL_GetWindowSurface(gWindow);
e571864cbc963e146e919633ca258a912181f760turn success;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load splash image
	gHelloWorld = SDL_LoadBMP("resources/hello_world.bmp");
	if(gHelloWorld == NULL)
	{
		std::cout << "Unable to load image " << "resources/hello_world.bmp" << "! SDL_Error: " << SDL_GetError();
		success = false;
	}

	return success;
}

void close()
{
	//Deallocate surface
	SDL_FreeSurface(gHelloWorld);
	gHelloWorld = NULL;

	//Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}