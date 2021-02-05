#include <iostream>
#include <exception>
#include <SDL2/SDL.h>
#include "engine.hxx"

//Starts up SDL and creates window
bool engine::init()
{
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cout << "SDL could not initiaize! SDL_Error: "
                  << SDL_GetError()
                  << std::endl;
        success = false;
    }
    else
    {
        //Create window
        gWindow = SDL_CreateWindow("Homework 3",
                                SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED,
                                SCREEN_WIDTH,
                                SCREEN_HEIGHT,
                                ::SDL_WINDOW_OPENGL);
        if(gWindow == NULL)
        {
            std::cout << "Window could not be created! SDL_Error: "
                      << SDL_GetError()
                      << std::endl;
            success = false;
        }
    }
    return success;
}
//Event loop
bool engine::event_handler_loop()
{
    bool return_result = false;
    //Handle events on queue
    while(SDL_PollEvent(&e)!=0)
    {
        //User request quit
        if(e.type == SDL_QUIT)
        {
            return_result = true;
        }
        //User presses a key
        else if (e.type == SDL_KEYDOWN)
        {
            std::cout << "Pressed key: ";
            //Select output based on key press
            switch (e.key.keysym.sym)
            {
            case SDLK_UP:
                std::cout << "UP"
                          << std::endl;
                break;

            case SDLK_DOWN:
                std::cout << "DOWN"
                          << std::endl;
                break;

            case SDLK_LEFT:
                std::cout << "LEFT"
                          << std::endl;
                break;

            case SDLK_RIGHT:
                std::cout << "RIGHT"
                          << std::endl;
                break;

            default:
                std::cout << "Unimplemented key"
                          << std::endl;
                break;
            }
        }
        else if (e.type == SDL_MOUSEBUTTONDOWN)
        {
            std::cout << "Pressed mouse button: ";
            //Select output based on key press
            switch (e.button.button)
            {
            case SDL_BUTTON_LEFT:
                std::cout << "SDL_BUTTON_LEFT"
                          << std::endl;
                break;

            case SDL_BUTTON_MIDDLE:
                std::cout << "SDL_BUTTON_MIDDLE"
                          << std::endl;
                break;

            case SDL_BUTTON_RIGHT:
                std::cout << "SDL_BUTTON_RIGHT"
                          << std::endl;
                break;

            case SDL_BUTTON_X1:
                std::cout << "SDL_BUTTON_X1"
                          << std::endl;
                break;

            case SDL_BUTTON_X2:
                std::cout << "SDL_BUTTON_X2"
                          << std::endl;
                break;

            default:
                std::cout << "Unimplemented mouse button"
                          << std::endl;
                break;
            }
        }
    }
    return return_result;
}
//Update the window screen
void engine::update_window()
{
    //Update the surface
    SDL_UpdateWindowSurface(gWindow);
}
//Frees media and shuts down SDL
void engine::close()
{
    //Destroy window
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;

    //Quit SDL subsystems
    SDL_Quit();
}
engine::~engine() {}
