cmake_minimum_required(VERSION 3.18.0)
project(Homework4.3 VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# EXECUTABLES
add_executable(draw_triangle src/main.cxx
                     src/canvas.hxx
                     src/canvas.cxx
                     src/line_render.hxx
                     src/line_render.cxx)

# COMPILE FEATURES
target_compile_features(draw_triangle PUBLIC cxx_std_17)
