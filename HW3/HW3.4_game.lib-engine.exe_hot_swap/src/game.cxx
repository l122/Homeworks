#include <iostream>
#include <thread>
#include <chrono>
#include <ctime>
#include "game.hxx"

game::game()
{
    std::cout << "We are in game and the current time is "
              << std::flush;
}
void game::do_game()
{
//    auto start = std::chrono::system_clock::now();
    // Some computation here
    auto time = std::chrono::system_clock::now();

//    std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t current_time = std::chrono::system_clock::to_time_t(time);

    std::cout << std::ctime(&current_time)
              << std::flush;

    //Sleep for 1 second
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}




