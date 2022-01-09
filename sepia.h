#ifndef _SEPIA_H_
#define _SEPIA_H_
#include "decorator.h"

class Image;

class Sepia: public Decorator {
  public:
    Sepia(Image *img);
    void render(PPM &ppm) override;
};

#endif

