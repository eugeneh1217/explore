#ifndef IO_H
#define IO_H
#include <string>

class Image
{
    unsigned char *_image;
    std::string _name;
    int _width, _height, _channels;

    public:
        Image(std::string const&);
        std::string name();
        unsigned int width();
        unsigned int height();
        unsigned int channels();
        unsigned char *image();
};

#endif
