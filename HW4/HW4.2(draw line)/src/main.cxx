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

    //Declare an image object for output into a file
    Canvas image;
    //Declare a render_line object
    line_render line(image, WIDTH, HEIGHT);

    //Fill the image with the color
    std::fill(image.begin(), image.end(), black);
    //or
    //line.clear(red);

    //Draw a line

    //Declare a position object
    position pos1{0, 0},
            pos2{WIDTH - 1, HEIGHT - 1};

    line.draw_line(pos1, pos2, red);

    //Set output file name
    const char* file_name = "image.ppm";
    //Save file
    image.save_image(file_name);


    // Check if image was saved correctly
    if(!check_file(image, file_name)) return EXIT_FAILURE;

    return EXIT_SUCCESS;
}
