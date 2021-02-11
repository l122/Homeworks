cmake_minimum_required(VERSION 3.18.0)
project(Homework4.1 VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# EXECUTABLES
add_executable(HW4.1 src/main.cxx
                     src/canvas.hxx
                     src/canvas.cxx)

# COMPILE FEATURES
target_compile_features(HW4.1 PUBLIC cxx_std_17)
