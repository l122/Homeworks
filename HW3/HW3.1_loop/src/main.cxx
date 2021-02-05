#include<iostream>
#include <SDL2/SDL.h>

//***************** GLOBAL CONSTANTS ***********************************
//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//***************** Function declarations *****************************
//Starts up SDL and creates window
bool init();
//Event loop
bool event_handler_loop(SDL_Event&);
//Frees media and shuts down SDL
void close();

//***************** Global variables **********************************
//The window we'll be rendering to
SDL_Window* gWindow = NULL;

int main (int argc, char * args[])
{
    //Main loop flag
    bool quit = false;

    //Start up SDL and create window
    if(!init())
    {
        std::cout << "Failed to initialize!" << std::endl;
        return EXIT_FAILURE;
    }
    else
    {
        //do something else
    }

    //Event handler
    SDL_Event e;

    //Main loop
    while (!quit)
    {
        //Handle events on queue
        quit = event_handler_loop(e);

        /*        while(SDL_PollEvent(&e)!=0)
        {
            //User request quit
            if(e.type == SDL_QUIT)
            {
                quit = true;
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
*/

        //Update the surface
        SDL_UpdateWindowSurface(gWindow);
    }

    //Free resourcess and close SDL
    close();

    return std::cout.good() ? EXIT_SUCCESS : EXIT_FAILURE;
}

bool init()
{
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cout << "SDL could not initiaize! SDL_Error: "
                  << SDL_GetError();
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
        else
        {
            //do something else
        }
    }
    return success;
}

bool event_handler_loop(SDL_Event& e)
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

void close()
{
    //Destroy window
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;

    //Quit SDL subsystems
    SDL_Quit();
}
