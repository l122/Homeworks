#include <algorithm>
#include <cmath>

#include "line_render.hxx"

bool check_bound(const position& pos)
{
    bool result = true;
    if (pos.x < 0)
    {
       std::cout << "x = " << pos.x << " < 0" << std::endl;
       result = false;
    }
    if (pos.x > WIDTH)
    {
        std::cout << "x = " << pos.x << " > " << WIDTH << std::endl;
        result = false;
    }
    if (pos.y < 0)
    {
        std::cout << "y = " << pos.y << " < 0" << std::endl;
        result = false;
    }
    if (pos.y > HEIGHT)
    {
        std::cout << "y = " << pos.y << " > " << HEIGHT << std::endl;
        result = false;
    }

    return result;
}

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
    position s, e, swap;
    int flag = 0;
   // std::cout << "Starting point: x=" << start.x << ", y=" << start.y << std::endl;
   // std::cout << "Ending point: x=" << end.x << ", y=" << end.y << std::endl;

    if (!(check_bound(start) && check_bound(end)))
    {
        std::cout << "The line cannot be displayed correctly" << std::endl;
        result.push_back({0,0});
        return result;
    }

    //Check the slope direction    
    if (abs(start.x - end.x) >= abs(start.y - end.y))
    {
        //Go along X-axis
        // If the end point has a greater X, then swap them
        if (start.x > end.x)
        {
            s.x = end.x;
            s.y = end.y;
            e.x = start.x;
            e.y = start.y;
        }
        else
        {
            s.x = start.x;
            s.y = start.y;
            e.x = end.x;
            e.y = end.y;
        }
    }
    else
    {
        //Go along Y-axis
        // If the end point has a greater X, then swap them
        if (start.y > end.y)
        {
            s.x = end.y;
            s.y = end.x;
            e.x = start.y;
            e.y = start.x;
        }
        else
        {
            s.x = start.y;
            s.y = start.x;
            e.x = end.y;
            e.y = end.x;
        }
        flag = 1;
    }


    // Using the principle of Bresenham's line algorithm
    //https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm
    int deltax = abs(e.x - s.x);
    int deltay = abs(e.y - s.y);
    int error = 0;
    //int deltaerr = (deltay + 1);
    int deltaerr = deltay;
    int diry = e.y - s.y;

    if (diry > 0) diry = 1;
    if (diry < 0) diry = -1;

    do
    {
       if (flag) //Swap X and Y
       {
            swap.x = s.y;
            swap.y = s.x;
            result.push_back(swap);
            //std::cout << "swap.x=" << swap.x << ", swap.y=" << swap.y << std::endl;
       }
       else
       {
           result.push_back(s);
           //std::cout << "x=" << s.x << ", y=" << s.y << std::endl;
       }
       error += deltaerr;
       if (error >= deltaerr)
       {
           s.y+=diry;
           //error = error - (deltax + 1);
           error = error - deltax;
       }
       ++s.x;
    }while(s.x <= e.x);

  //  std::cout << "Starting point: x=" << start.x << ", y=" << start.y << std::endl;
  // std::cout << "Ending point: x=" << end.x << ", y=" << end.y << std::endl;

    return result;
}

void line_render::draw_line(position start, position end, color c)
{
    vector_of_pixels pxs = pixels_positions(start, end);
    std::for_each(begin(pxs), std::end(pxs), [&](auto& pos) {set_pixel(pos, c);});
}


