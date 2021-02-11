#pragma once

#include <array>
#include <cstdint>
#include <cstddef>
#include <string>
#include <fstream>
#include <iostream>
#include <cmath>
#include <vector>

constexpr size_t width = 320;
constexpr size_t height = 240;

const size_t buffer_size = width * height;

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


class Canvas
{
public:
    void save_image(const std::string&);
    void load_image(const std::string&);
    color get_pixel(size_t x, size_t y) const;
    void set_pixel(size_t x, size_t y, color value);
    bool operator==(const Canvas& other) const;
    bool operator!=(const Canvas& other) const;
    auto begin() {return pixels.begin();}
    auto end() {return pixels.end();}

private:
    std::array<color, buffer_size> pixels; //can be as this: color pixels[buffer_size];
};


