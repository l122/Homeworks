#include "line_render.hxx"
#include "canvas.hxx"

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

    //Declare a position object
    position p1, p2;

    //Draw grid
    for (int x = 0; x < WIDTH; x+=20)
    {
        p1.x = x;
        p1.y = 0;
        p2.x = x;
        p2.y = HEIGHT - 1;
        line.draw_line(p1, p2, green);
    }
    for(int y = 0; y < HEIGHT; y+=20)
    {
        p1.x = 0;
        p1.y = y;
        p2.x = WIDTH - 1;
        p2.y = y;
        line.draw_line(p1, p2, green);
    }

    // Draw some more lines

    p1.x = 20;
    p1.y = 120;
    p2.x = 200;
    p2.y = 40;

    line.draw_line(p1, p2, white);

    p1.x = 20;
    p1.y = 40;
    p2.x = 200;
    p2.y = 120;

    line.draw_line(p1, p2, white);

    p1.x = 60;
    p1.y = 20;
    p2.x = 160;
    p2.y = 200;

    line.draw_line(p1, p2, blue);

    p1.x = 210;
    p1.y = 20;
    p2.x = 160;
    p2.y = 200;

    line.draw_line(p1, p2, blue);

    //Set output file name
    const char* file_name = "image.ppm";
    //Save file
    image.save_image(file_name);


    // Check if image was saved correctly
    if(!check_file(image, file_name)) return EXIT_FAILURE;

    return EXIT_SUCCESS;
}
