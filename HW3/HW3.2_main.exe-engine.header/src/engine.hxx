#pragma once
#include <SDL2/SDL.h>

//***************** GLOBAL CONSTANTS ***********************************
//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

class engine
{
private:
    //The window we'll be rendering to
    SDL_Window* gWindow = NULL;
    //Event handler
    SDL_Event e;

public:
    ~engine();

    //Starts up SDL and creates window
    bool init();
    //Event loop
    bool event_handler_loop();
    //Update the window screen
    void update_window();
    //Frees media and shuts down SDL
    void close();
};
