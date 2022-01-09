#ifndef _DECORATOR_H_
#define _DECORATOR_H_
#include "image.h"

class Decorator: public Image {
  protected:
    Image * img;
  public:
    Decorator( Image * img );
    virtual void render(PPM &ppm) = 0;
    virtual ~Decorator();
};

#endif
