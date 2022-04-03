#include <string>
#include <stdexcept>
#include <iostream>
#include <exception>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include "image_class.h"

Image::Image(std::string const &name)
{
    _name = name;
    _image = stbi_load(name.c_str(), &_width, &_height, &_channels, 0);
    if (_image == NULL)
    {
        throw std::invalid_argument("File not found");
    }
}

std::string Image::name()
{
    return _name;
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

Perceptron::Perceptron(double *weights, unsigned width, unsigned height)
{
    _weights = weights;
    _width = width;
    _height = height;
}

double Perceptron::Classify(Image img)
{
    if (_width != img.width() or _height != img.height())
    {
        throw std::invalid_argument("Image dimensions do not match weight dimensions");
    }
    if (img.channels() != 1)
    {
        throw std::invalid_argument("Perceptron expects a single-channel image");
    }
    unsigned char *img_pixels = img.image();
    double classification{0};
    for (unsigned i {0}; i < _width * _height; ++ i)
    {
        classification += _weights[i] * img_pixels[i];
    }
    return classification;
}

Trainer::Trainer(Image *images, int *classes, unsigned count)
{
    _images = images;
    _classes = classes;
    _count = count;
    _learning_rate = 1;
}

void Trainer::Train(Perceptron &trainee, double split)
{
    for (int i = 0; i < _count * split; ++ i)
    {
        TrainImage(trainee, i);
    }
}

void Trainer::TrainImage(Perceptron &trainee, const int &index)
{
    if (trainee.Classify(_images[index]))
    {
        return;
    }
    auto img = _images[index].image();
    for (int i{0}; i < trainee._width * trainee._height; ++ i)
    {
        trainee._weights[i] -= img[i] * _learning_rate;
    }
}
