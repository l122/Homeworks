cmake_minimum_required(VERSION 3.18.0)
project(Homework3 VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# EXECUTABLES
add_executable(main_dynamic src/main.cxx
                            src/engine.cxx
                            src/engine.hxx
               )
add_executable(main_static src/main.cxx
                           src/engine.cxx
                           src/engine.hxx
               )

# COMPILE FEATURES
target_compile_features(main_dynamic PUBLIC cxx_std_17)
target_compile_features(main_static PUBLIC cxx_std_17)

# FIND PACKAGES
find_package(SDL2 REQUIRED)

# LINKING LIBRARIES
target_link_libraries(main_dynamic PRIVATE SDL2)
target_link_libraries(main_static PRIVATE SDL2::SDL2-static)
