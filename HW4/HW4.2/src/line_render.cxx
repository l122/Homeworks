#include <algorithm>
#include <cmath>

#include "line_render.hxx"

line_render::line_render(Canvas& buffer_, size_t width, size_t height)
    : buffer(buffer_)
    , w(width)
    , h(height)
{
}

void line_render::clear(color c)
{
    std::fill(buffer.begin(), buffer.end(), c);
}

void line_render::set_pixel(position p, color c)
{
    buffer.set_pixel(p.x,p.y, c);
}
vector_of_pixels line_render::pixels_positions(position start, position end)
{
    vector_of_pixels result;
    position curr_pos = {start.x, start.y};
    // Using Bresenham's line algorithm
    //https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm
    int deltax = abs(end.x - start.x);
    int deltay = abs(end.y - start.y);
    int error = 0;
    int deltaerr = (deltay + 1);
    int diry = end.y - start.y;

    if (diry > 0) diry = 1;
    if (diry < 0) diry = -1;

    for (curr_pos.x = start.x; curr_pos.x < end.x; ++curr_pos.x)
    {
       result.push_back(curr_pos);
       error += deltaerr;
       if (error >= deltaerr)
       {
           curr_pos.y+=diry;
           error = error - (deltax + 1);
       }
    }
    return result;
}

void line_render::draw_line(position start, position end, color c)
{
    vector_of_pixels pxs = pixels_positions(start, end);
    std::for_each(begin(pxs), std::end(pxs), [&](auto& pos) {set_pixel(pos, c);});
}

