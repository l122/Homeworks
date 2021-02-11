#include <iostream>
#include <filesystem>
#include <chrono>

#include <SDL2/SDL.h>
#include "engine.hxx"
#include "game.hxx"

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
    //Load and reload game lib
game* reload_game(game*         old,
                  const char*   library_name,
                  const char*   tmp_library_name,
                  engine&       engine,
                  void*&        old_handle)
{
    using namespace std::filesystem;

    if (old)
    {
        SDL_UnloadObject(old_handle);
    }

    if (std::filesystem::exists(tmp_library_name))
    {
        if (0 != remove(tmp_library_name))
        {
            std::cerr << "error: can't remove: " << tmp_library_name
                      << std::endl;
            return nullptr;
        }
    }

    try
    {
        copy(library_name, tmp_library_name); // throw on error
    }
    catch (const std::exception& ex)
    {
        std::cerr << "error: can't copy [" << library_name << "] to ["
                  << tmp_library_name << "]" << std::endl;
        return nullptr;
    }

    void* game_handle = SDL_LoadObject(tmp_library_name);

    if (game_handle == nullptr)
    {
        std::cerr << "error: failed to load: [" << tmp_library_name << "] "
                  << SDL_GetError() << std::endl;
        return nullptr;
    }

    old_handle = game_handle;

    void* create_game_func_ptr = SDL_LoadFunction(game_handle, "create_game");

    if (create_game_func_ptr == nullptr)
    {
        std::cerr << "error: no function [create_game] in " << tmp_library_name
                  << " " << SDL_GetError() << std::endl;
        return nullptr;
    }
    // void* destroy_game_func_ptr = SDL_LoadFunction(game_handle,
    // "destroy_game");

    typedef decltype(&create_game) create_game_ptr;

    auto create_game_func =
        reinterpret_cast<create_game_ptr>(create_game_func_ptr);

    om::game* game = create_game_func(&engine);

    if (game == nullptr)
    {
        std::cerr << "error: func [create_game] returned: nullptr" << std::endl;
        return nullptr;
    }
    return game;
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



int main (int, char *[])
{
    //Create an engine object
    engine* my_engine = new engine();

    //Create a game object
    game* my_game = new game();

    //Start up SDL and create window
    if(!my_engine->init())
    {
        std::cout << "Failed to initialize!" << std::endl;
        return EXIT_FAILURE;
    }

    //Get game lib name
    const char* lib_name = "./libgame.so";
    //Set name for a temp lib
    const char* tmp_lib_file = "./temp.so";

    bool continue_loop = true;
    //Main loop
    while (continue_loop)
    {
        //Check if game lib has been updated and reloaded


        //Handle events
        continue_loop = !my_engine->event_handler_loop();
        //Do game logic
        my_game->do_game();
        //Update the window
        my_engine->update_window();
    }

    //Free resourcess and close SDL
    my_engine->close();

    //Destroy engine
    delete my_engine;

    return std::cout.good() ? EXIT_SUCCESS : EXIT_FAILURE;
}
