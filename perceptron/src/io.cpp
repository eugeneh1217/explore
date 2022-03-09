#include <string>
#include <stdexcept>
#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include "io.h"

Image::Image(std::string const &name)
{
    _name = name;
    _image = stbi_load(name.c_str(), &_width, &_height, &_channels, 0);
    if (_image == NULL)
    {
        throw std::invalid_argument("File not found");
    }
}

unsigned int Image::width()
{
    return _width;
}

unsigned int Image::height()
{
    return _height;
}

unsigned int Image::channels()
{
    return _channels;
}

unsigned char *Image::image()
{
    return _image;
}