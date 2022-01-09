#include "sepia.h"
#include "image.h"
#include "exception.h"

#include <iostream>
#include <sstream>
#include <fstream>
using std::ostringstream;
using std::endl;
using std::ifstream;

Sepia::Sepia(Image *img) : Decorator{img} {}


void Sepia::render(PPM &ppm) {

    // first render the existing image
    img->render(ppm);

    // get all the pixels from ppm
    std::vector<Pixel> &pixels = ppm.getPixels();
    // get the width and height from original ppm
    int &width = ppm.getWidth();
    int &height = ppm.getHeight();
    
    // create a temp vector of pixels to store the transformed pixels
    std::vector<Pixel> tempPixels;

    // initialize an current pixel and its rgb to help append the tempPixels later 
    Pixel cur = pixels[0];
    int r = 0;
    int g = 0;
    int b = 0;

    // Modifies the internal representation (PPM) so that it now represents an image that has a sepia filter applied to
    // the image. Apply the following formulae (exactly as given) to each pixel in the image.
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cur = pixels[i * width + j];
            r = cur.r * 0.393 + cur.g * 0.769 + cur.b * 0.189;
            g = cur.r * 0.349 + cur.g * 0.686 + cur.b * 0.168;
            b = cur.r * 0.272 + cur.g * 0.534 + cur.b * 0.131;
            // if any rgb exceeds 255, set it to the max which is 255
            if (r>255) {r=255;}
            if (g>255) {g=255;}
            if (b>255) {b=255;}
            // add the transformed pixel to temp
            tempPixels.emplace_back(Pixel{r,g,b});
        }
    }

    // assign the tempPixels to be the new pixels for img, this transformation completed
    pixels = tempPixels;
}
