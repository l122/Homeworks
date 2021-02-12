#include "triangle_render.hxx"

triangle_render::triangle_render(Canvas& buffer,
                                 size_t width,
                                 size_t height)
    : line_render(buffer, width, height)
{
}
vector_of_pixels triangle_render::pixels_positions_triangle(position p1,
                                                   position p2,
                                                   position p3)
{
    vector_of_pixels result,
                    temp;

    //Get a vector array of all pixel coordinates between each point
    //and append it in one vector array - result
    result = line_render::pixels_positions(p1, p2);
    temp = line_render::pixels_positions(p2, p3);
    result.insert(result.end(), temp.begin(), temp.end());
    temp = line_render::pixels_positions(p1, p3);
    result.insert(result.end(), temp.begin(), temp.end());

    return result;
}
void triangle_render::draw_triangle (const vector_of_pixels& vertexes,
                                     const color& c)
{
    vector_of_pixels triangles,
                    temp;
    int vertexes_qty = vertexes.size();
    if ((vertexes_qty / 3) < 1)
    {
        std::cout << "Invalid quantity of vertexes - "
                  << vertexes_qty
                  << std::endl;
    }
    else
    {
        // Create a vector array of all pixels positions of trianlge lines
        position p1, p2, p3;
        for (int i = 0; i < (vertexes_qty / 3); ++i)
        {
            p1 = vertexes.at(i * 3 + 0);
            p2 = vertexes.at(i * 3 + 1);
            p3 = vertexes.at(i * 3 + 2);
            std::cout << "p1: x= " << p1.x << ", y= " << p1.y << std::endl;

            std::cout << "p2: x= " << p2.x << ", y= " << p2.y << std::endl;

            std::cout << "p3: x= " << p3.x << ", y= " << p3.y << std::endl;

            temp = pixels_positions_triangle(p1, p2, p3);
            triangles.insert(triangles.begin(), temp.begin(), temp.end());
        }
    }
    //Apply color to every pixel position
    for (auto pos : triangles)
    {
        set_pixel(pos, c);
    }

}
