#pragma once

#include <array>
#include <cstdint>
#include <cstddef>
#include <string>
#include <fstream>
#include <iostream>
#include <cmath>
#include <vector>

constexpr size_t WIDTH = 320;
constexpr size_t HEIGHT = 240;

const size_t buffer_size = WIDTH * HEIGHT;

//Structure for color data;
//alligned to 3 Bytes
#pragma pack(push, 1)
struct color
{
    uint8_t r = 0;
    uint8_t g = 0;
    uint8_t b = 0;
    friend bool operator==(const color& l, const color& r);
};
#pragma pack(pop)

//The class for storing and processing all the pixels in an image
//Each pixel is represented as a structure of 3-Byte colors
//It is basically an image itself stored in an array
class Canvas
{
public:
    //Saves an image to a file with extension PPM
    void save_image(const std::string&);
    //Loads an image from a PPM-file
    void load_image(const std::string&);
    //Gets the colored pixel at given coordinates
    color get_pixel(size_t x, size_t y) const;
    //Sets the color to a pixel at given coordinates
    void set_pixel(size_t x, size_t y, color value);
    bool operator==(const Canvas& other) const;
    bool operator!=(const Canvas& other) const;
    auto begin() {return pixels.begin();}
    auto end() {return pixels.end();}

private:
    //An array of all pixels on Canvas
    std::array<color, buffer_size> pixels; //can be as this: color pixels[buffer_size];
};


