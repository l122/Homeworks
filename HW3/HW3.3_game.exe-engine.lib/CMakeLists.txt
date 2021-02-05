cmake_minimum_required(VERSION 3.18.0)
project(Homework3 VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# ADD LIBRARIES
add_library(engine_dynamic SHARED src/engine.cxx
                                  src/engine.hxx)
target_compile_features(engine_dynamic PUBLIC cxx_std_17)

add_library(engine_static STATIC src/engine.cxx
                                 src/engine.hxx)
target_compile_features(engine_static PUBLIC cxx_std_17)

# EXECUTABLES
add_executable(game_dynamic src/game.cxx)
target_compile_features(game_dynamic PUBLIC cxx_std_17)

add_executable(game_static src/game.cxx)
target_compile_features(game_static PUBLIC cxx_std_17)


# FIND PACKAGES
find_package(SDL2 REQUIRED)

# LINKING LIBRARIES
target_link_libraries(engine_dynamic PRIVATE SDL2)
target_link_libraries(engine_static PRIVATE SDL2::SDL2-static)
target_link_libraries(game_dynamic PRIVATE engine_dynamic)
target_link_libraries(game_static PRIVATE engine_static)
