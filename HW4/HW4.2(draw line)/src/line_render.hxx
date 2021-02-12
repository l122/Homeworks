#pragma once

#include "canvas.hxx"

struct position
{
    int x = 0;
    int y = 0;
};

//Array of all pixels of line
using vector_of_pixels = std::vector<position>;

struct irender
{
    virtual void clear(color) = 0;
    virtual void set_pixel(position, color) = 0;
    virtual vector_of_pixels pixels_positions(position start, position end) = 0;

//    virtual ~irender(); //doesn't let to compile the project
};

struct line_render : irender
{
    line_render(Canvas& buffer_, size_t width, size_t height);

    void clear(color) override;
    void set_pixel(position, color) override;
    //Return a vector of position of each pixel in a line
    vector_of_pixels pixels_positions(position start, position end) override;
    //Sets a color for the vector of pixels in a line
    void draw_line(position start, position end, color);


private:
    //An array of all pixels in a line
    Canvas& buffer;
    const size_t w;
    const size_t h;
};


