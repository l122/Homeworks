#include <iostream>
#include "engine.hxx"

int main (int, char *[])
{
    //Create an engine object
    engine* my_engine = new engine();

    //Start up SDL and create window
    if(!my_engine->init())
    {
        std::cout << "Failed to initialize!" << std::endl;
        return EXIT_FAILURE;
    }

    //Main loop
    while (!my_engine->event_handler_loop())
    {
        //Update the window
        my_engine->update_window();
    }

    //Free resourcess and close SDL
    my_engine->close();

    //Destroy engine
    delete my_engine;

    return std::cout.good() ? EXIT_SUCCESS : EXIT_FAILURE;
}


