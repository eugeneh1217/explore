#ifndef IO_H
#define IO_H
#include <string>

class Image;
class Perceptron;
class Trainer;

class Image
{
    unsigned char *_image;
    std::string _name;
    int _width, _height, _channels;

    public:
        Image(std::string const&);
        std::string name();
        unsigned width();
        unsigned height();
        unsigned channels();
        unsigned char *image();
};

class Perceptron
{
    friend Trainer;

    public:
        Perceptron(double *, unsigned, unsigned);
        double Classify(Image);

    private:
        double *_weights;
        unsigned _width;
        unsigned _height;
};

class Trainer
{
    public:
        Trainer(Image *, int *, unsigned);
        void Train(Perceptron &, double);
    
    private:
        Image *_images;
        int *_classes;
        unsigned _count;
        double _learning_rate;
        void TrainImage(Perceptron &, const int &);
};

#endif
