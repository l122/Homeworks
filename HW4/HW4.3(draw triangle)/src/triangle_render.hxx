#pragma once
#include "line_render.hxx"

struct triangle_render : line_render
{
    triangle_render(Canvas& buffer, size_t width, size_t height);
    virtual vector_of_pixels pixels_positions_triangle(position p1,
                                                       position p2,
                                                       position p3);
    void draw_triangle (const vector_of_pixels& vertexes, const color& c);
};

