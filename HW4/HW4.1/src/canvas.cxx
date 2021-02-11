#include "canvas.hxx"

void Canvas::save_image(const std::string& file_name)
{
    std::ofstream out_file;
    out_file.exceptions(std::ios_base::failbit);
    out_file.open(file_name, std::ios_base::binary);
    out_file << "P6\n"
             << width << ' ' << height << ' ' << 255
             << '\n';
    std::streamsize buf_size =
            static_cast<std::streamsize>(sizeof(color) * pixels.size());
    out_file.write(reinterpret_cast<const char*>(pixels.data()), buf_size);
}

void Canvas::load_image(const std::string& file_name)
{
    std::ifstream in_file;
    in_file.exceptions(std::ios_base::failbit);
    in_file.open(file_name, std::ios_base::binary);
    std::string header;
    size_t image_width = 0;
    size_t image_height = 0;
    std::string color_format;
    in_file >> header >> image_width >> image_height >> color_format
            >> std::ws;
    if (pixels.size() != image_height * image_width)
    {
        throw std::runtime_error("image size doesn't match");
    }
    std::streamsize buf_size =
            static_cast<std::streamsize>(sizeof(color) * pixels.size());
    in_file.read(reinterpret_cast<char*>(pixels.data()), buf_size);
}

color Canvas::get_pixel(size_t x, size_t y) const
{
    const size_t liner_index_in_buffer = x + y * width;
    return pixels.at(liner_index_in_buffer);
}

void Canvas::set_pixel(size_t x, size_t y, color value)
{
    const size_t liner_index_in_buffer = x + y * width;
    color& target_pixel = pixels.at(liner_index_in_buffer);
    target_pixel = value;
}

bool Canvas::operator==(const Canvas& other) const
{
    return pixels == other.pixels;
}

bool Canvas::operator!=(const Canvas& other) const
{
    return !(*this == other);
}

//This is not compileted if defined here instead of the header
//auto Canvas::begin() {return pixels.begin();}
//auto Canvas::end() {return pixels.end();}

//Overload the operator '==' for structure color
bool operator==(const color& l, const color& r)
{
    return l.r==r.r && l.g==r.g && l.b==r.b;
}
