#include "canvas.hxx"
#include "triangle_render.hxx"

bool check_file(const Canvas& image, const char* file_name)
{
    bool result = true;
    //Declare an image object for input from file
    Canvas image_loaded;
    //Try to open a file and get image data
    image_loaded.load_image(file_name);
    //Check if image was loaded
    if (image != image_loaded)
    {
        std::cerr << "image != image_loaded\n";
        result = false;
    }
    else
    {
        std::cout << "image == image_loaded\n";
    }
    return result;
}

int main (int argc, char * args[])
{
    //Create objects of colors
    const color red = {255, 0, 0};
    const color green = {0, 255, 0};
    const color blue = {0, 0, 255};
    const color black = {0, 0, 0};
    const color white = {255, 255, 255};

    //Declare an image object for output into a file
    Canvas image;
    //Declare a render_line object
    line_render line(image, WIDTH, HEIGHT);

    //Fill the image with the color
    std::fill(image.begin(), image.end(), black);
    //or
    //line.clear(red);

    //Draw lines
    //Declare a position object
    position p1{0, HEIGHT - 1},
            p2{WIDTH-1, 0},
            p3{0,0},
            p4{WIDTH-1, HEIGHT-1};


    //Draw a frame around the image
    line.draw_line(p3, p1, red);
    line.draw_line(p3, p2, red);
    line.draw_line(p4, p1, red);
    line.draw_line(p4, p2, red);


    //Draw triangles
    triangle_render t_render(image, WIDTH, HEIGHT);
    p1.x=103;
    p1.y=166;
    p2.x=297;
    p2.y=115;
    p3.x=273;
    p3.y=175;

    vector_of_pixels vertexes = {p1, p2, p3};
    //t_render.draw_triangle(vertexes, white);

    //line.draw_line(p1, p3, red);
   // line.draw_line(p3, p2, green);
   // line.draw_line(p2, p1, blue);

    color c;

    for (int i = 0; i < 10; ++i)
    {
        vertexes.clear();
        p1.x = rand() % 320;
        p1.y = rand() % 240;
        std::cout << "Triangle " << i + 1 << ":" << std::endl;
        std::cout << "p1: x= " << p1.x << ", y= " << p1.y << std::endl;
        vertexes.push_back(p1);
        p2.x = rand() % 320;
        p2.y = rand() % 240;
        std::cout << "p2: x= " << p2.x << ", y= " << p2.y << std::endl;
        vertexes.push_back(p2);
        p3.x = rand() % 320;
        p3.y = rand() % 240;
        std::cout << "p3: x= " << p3.x << ", y= " << p3.y << std::endl;
        vertexes.push_back(p3);

        c.r = rand() % 256;
        c.g = rand() % 256;
        c.b = rand() % 256;

        t_render.draw_triangle(vertexes, c);
    }


    //Set output file name
    const char* file_name = "image.ppm";
    //Save file
    image.save_image(file_name);


    // Check if image was saved correctly
    if(!check_file(image, file_name)) return EXIT_FAILURE;

    return EXIT_SUCCESS;
}
