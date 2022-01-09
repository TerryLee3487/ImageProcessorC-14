#ifndef _ROTATE_H_
#define _ROTATE_H_
#include "decorator.h"

class Image;

class Rotate: public Decorator {
  public:
    Rotate(Image *img);
    void render(PPM &ppm) override;
};

#endif

