#include "canvas.hxx"

int main (int argc, char * args[])
{
    //Set color for the image
    const color green = {0, 255, 0};
    //Declare an image object for output into a file
    Canvas image;
    //Fill the image with the color
    std::fill(image.begin(), image.end(), green);
    //Set output file name
    const char* file_name = "image.ppm";
    //Save file
    image.save_image(file_name);
    //Declare an image object for input from file
    Canvas image_loaded;
    //Try to open a file and get image data
    image_loaded.load_image(file_name);

    //Check if image was loaded
    if (image != image_loaded)
    {
        std::cerr << "image != image_loaded\n";
        return EXIT_FAILURE;
    }
    else
    {
        std::cout << "image != image_loaded\n";
    }

    return EXIT_SUCCESS;
}
